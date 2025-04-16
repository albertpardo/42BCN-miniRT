/* 
 * Code from : https://github.com/qst0/ft_libgfx#minilibx
 */
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

int main(void)
{
	void *mlx;
	void *window;
  
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Title");
	if (window == NULL)
	{
		printf("new windw error ! \n");
		exit (1);
	}
    mlx_loop(mlx);
	return (0);
}
