// Pone el char '|' tras cada letra char del string1

#include <mlx.h>

#define MAX_X 1920
#define MAX_Y 1080

int	main(void)
{
	void	*mlx;
	void    *mlx_win;
	char	*str = "Hola Mundo";

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, MAX_X, MAX_Y, "String");

	mlx_string_put(mlx, mlx_win, 100, 100, 0x0000FF00, str);
	mlx_loop(mlx);
}	
