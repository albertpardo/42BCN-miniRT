/* 
 * Code from: 
 * https://elearning.intra.42.fr/notions/minilibx/subnotions/mlx-events/videos/minilibx-events
 */

/*
 * In https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html#mlx_get_data_addr
 * coments:
 * This function is NOT recommended for use. It will lock the window output, force a refresh and a recalculation. It is therefore suggested to render a image and push that using the mlx_put_image_to_window functioni
 *
 * En https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#writing-pixels-to-a-image
 * indica:
 *
 *First of all, we should take into account that the mlx_pixel_put function is very, very slow. This is because it tries to push the pixel instantly to the window (without waiting for the frame to be entirely rendered)
 */

#include <mlx.h>

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
  
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
    mlx_loop(mlx_ptr);
	return (0);
}
