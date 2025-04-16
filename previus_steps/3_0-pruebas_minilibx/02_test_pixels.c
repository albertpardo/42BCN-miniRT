/* 
 * Code from: 
 * https://elearning.intra.42.fr/notions/minilibx/subnotions/mlx-events/videos/minilibx-events
 *
 * En https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#writing-pixels-to-a-image
 *  Comenta que es mejor usar "mlx_new_image" tener un espacio para la imagen ase se ponen los pixels o la imagen y cuand este actualizada usar "mlx_put_image_to_window" para que le renderice en pantalla.
 */

#include <mlx.h>

#define MAX_X 500
#define MAX_Y 500
#define MAX_COLOR 0x00FFFFFF

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		rgb_color;

	x = 0;
	y = 0;
	rgb_color = 0x0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, MAX_X, MAX_Y, "mlx 42");
	while(y <= MAX_Y)
	{
		x = 0;
		while( x < MAX_X)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, rgb_color);
			rgb_color++;
			if (rgb_color == (MAX_COLOR + 1))
				rgb_color = 0;
			x++;
		}
		y++;
	}
    mlx_loop(mlx_ptr);
	return (0);
}
