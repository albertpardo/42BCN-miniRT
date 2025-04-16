/*
 * https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#pushing-images-to-a-window
 */

#include <mlx.h>
#include <stdio.h>

#define MAX_X 1920
#define MAX_Y 1080
#define MAX_COLOR 0xFFFF

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*
 * my_mlx_pixel_put
 *
 *  Note that this will cause an issue. 
 *  Because an image is represented in real time in a window,
 *  	changing the same image will cause a bunch of screen-tearing when writing to it. 
 *  You should therefore create two or more images to hold your frames temporarily. 
 *  You can then write to a temporary image, 
 *  	so that you don’t have to write to the currently presented image.
 */

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst; // Acces to pixel postion in *data

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;  //Change the pixel color
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		offset;
	int		x;
	int 	y;
	int		rgb_color;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, MAX_X, MAX_Y, "Pixels");
	img.img = mlx_new_image(mlx, MAX_X, MAX_Y);
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = 1;
	y = 0;
	offset = (y * img.line_length + x * (img.bits_per_pixel / 8));
	printf("img.img = %p, img.bits_per_pixel = %d, img.line_length = %d, img.endian = %d \n",img.img, img.bits_per_pixel, img.line_length, img.endian);
	printf("offset (1, 0) = %d\n", offset);
	printf("img.line_length / offset = %d\n", img.line_length / offset);
	x = 0;
	y = 0;
	while(y < MAX_Y)
	{
		rgb_color = 0x0;
		x = 0;
		while( x < MAX_X)
		{
			my_mlx_pixel_put(&img, x, y, rgb_color);
			rgb_color++;
			if (rgb_color == (MAX_COLOR + 1))
				rgb_color = 0x0;
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
