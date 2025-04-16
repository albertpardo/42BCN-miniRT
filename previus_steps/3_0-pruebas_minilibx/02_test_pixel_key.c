/* 
 * Code from: 
 * https://elearning.intra.42.fr/notions/minilibx/subnotions/mlx-events/videos/minilibx-events
 */

#include <mlx.h>
#include <stdio.h>


int deal_key(int key, void *param)
{
	printf("key = %d, p = %p\n", key, param);
	return (0);
}

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
  
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *) 0);
	mlx_loop(mlx_ptr);
	return (0);
}
