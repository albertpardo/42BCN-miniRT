/* 
 * Code from: 
 * https://gontjarow.github.io/MiniLibX/mlx-tutorial-register-event-handlers.html 
 */

#include <mlx.h>
#include <stdio.h>

int mouse_event(int button, int x, int y, int *n)
{
	printf("Antes . Button = %d, x = %d, y = %d,  n=%d\n", button, x, y, *n);
	if (button == 5)
		*n += 1;
	else if (button == 4)
		*n -= 1;
	printf("Despues . Button = %d, x = %d, y = %d,  n=%d\n", button, x, y, *n);
	printf("-------------\n");
	
	return (0);
}

int main(void)
{
	void	*mlx;
	void	*win;
	int		n;
  
	n = 10;
	mlx = mlx_init();
 	win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Registering Events: MOUSE");
    mlx_mouse_hook(win, &mouse_event, &n);
    mlx_loop(mlx);
	return (0);
}
