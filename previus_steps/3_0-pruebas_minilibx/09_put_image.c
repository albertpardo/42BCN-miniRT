#include <mlx.h>
#include <stdio.h>
#include <unistd.h>   //para usar sleep(unsignet int seconds)

#define MAX_X 1920
#define MAX_Y 1080

int	main(void)
{
	void	*mlx;
	void    *mlx_win;
	void	*img;
	char	*relative_path = "./png-2702691_640_425.xpm";
	int		img_width = 645;
	int		img_height = 425;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, MAX_X, MAX_Y, "Cat");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		printf("Read error");
	else
		printf("Read OK");
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img, 400, 400);
	mlx_loop(mlx);
}	
