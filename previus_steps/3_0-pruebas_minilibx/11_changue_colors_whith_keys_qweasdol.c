/*
 * https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#pushing-images-to-a-window
 */

#include <mlx.h>
#include <stdio.h>

#define MAX_X 500
#define MAX_Y 500
#define E_KEY 14   	// +B
#define D_KEY 2		// -B
#define W_KEY 13	// +G
#define S_KEY 1		// -G
#define Q_KEY 12	// +R
#define A_KEY 0		// -R
#define O_KEY 31	// +T
#define L_KEY 37	// -T

typedef struct mlxdata
{
	void	*mlx;
	void	*mlx_win;
}				t_mlxdata;

typedef struct	s_data
{
	t_mlxdata	win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			fondo_color;
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

// Color functions
int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

void	putcolor(t_data *img,int color)
{
	int		x;
	int 	y;

	x = 0;
	y = 0;
	while(y < MAX_Y)
	{
		x = 0;
		while( x < MAX_X)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

int component_in_range(int comp)
{
    if (comp > 0xFF)
        comp = 0xFF;
	else if (comp < 0x00)
		comp = 0x00;
    return (comp);
}

int inc_componet(int comp, int inc)
{
    comp += inc;
    return (component_in_range(comp));
}

int inc_t(int trgb, int inc)
{
	return (create_trgb(inc_componet(get_t(trgb), inc), get_r(trgb), \
		   	get_g(trgb), get_b(trgb)));
}

int inc_r(int trgb, int inc)
{
	return (create_trgb(get_t(trgb), inc_componet(get_r(trgb), inc), \
			   	get_g(trgb), get_b(trgb)));
}

int inc_g(int trgb, int inc)
{
	return (create_trgb(get_t(trgb), get_r(trgb), inc_componet(get_g(trgb), inc), \
			   get_b(trgb)));
}

int inc_b(int trgb, int inc)
{
	return (create_trgb(get_t(trgb), get_r(trgb), get_g(trgb), \
			   inc_componet(get_b(trgb), inc)));
}
// end color


void changeComponent(t_data *imgptr, int (*f)(int trgb, int inc), int value)
{
	t_mlxdata win;
	
	win = imgptr->win;
	imgptr->fondo_color = (*f)(imgptr->fondo_color, value);
	putcolor(imgptr, imgptr->fondo_color);
	mlx_clear_window(win.mlx, win.mlx_win );
	mlx_put_image_to_window(win.mlx, win.mlx_win, imgptr->img, 0, 0);
}

void changeCompoPrint(int key, t_data *imgptr, int (*f)(int trgb, int inc), int value)
{
	changeComponent(imgptr, (*f), value);
	printf("%d, %d, %08x\n", key, value, imgptr->fondo_color);
}

/*
 * Uso puntero a funcion
 */

int deal_key(int key, t_data *imgptr)
{
	t_mlxdata win;
	
	win = imgptr->win;
	if (key == O_KEY)
		changeCompoPrint(key, imgptr, inc_t, 1);
	else if (key == L_KEY)
		changeCompoPrint(key, imgptr, inc_t, -1);
	else if (key == Q_KEY)
		changeCompoPrint(key, imgptr, inc_r, 1);
	else if (key == A_KEY)
		changeCompoPrint(key, imgptr, inc_r, -1);
	else if (key == W_KEY)
		changeCompoPrint(key, imgptr, inc_g, 1);
	else if (key == S_KEY)
		changeCompoPrint(key, imgptr, inc_g, -1);
	else if (key == E_KEY)
		changeCompoPrint(key, imgptr, inc_b, 1);
	else if (key == D_KEY)
		changeCompoPrint(key, imgptr, inc_b, -1);
	else
		printf("%d\n", key);
	return (0);
}

int	main(void)
{

	t_data		img;
	t_mlxdata	win;

	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, MAX_X, MAX_Y, "Pixels");
	img.win = win;
	img.img = mlx_new_image(win.mlx, MAX_X, MAX_Y);
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.fondo_color = 0x7F7F7F7F;
	putcolor(&img, img.fondo_color);
	mlx_key_hook(win.mlx_win, deal_key, &img);
	mlx_put_image_to_window(win.mlx, win.mlx_win, img.img, 0, 0);
	mlx_loop(img.win.mlx);
}
