/* 
 * Code from : https://github.com/qst0/ft_libgfx#minilibx
 */

#include "./minilibx-linux/mlx.h"

int main(void)
{
	void *mlx;
	void *window;
  
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Title");
    mlx_loop(mlx);
	return (0);
}
