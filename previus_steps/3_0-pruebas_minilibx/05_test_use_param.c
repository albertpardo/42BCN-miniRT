/* 
 * Code from:
 * https://gontjarow.github.io/MiniLibX/mlx-tutorial-event-param.html
 */

#include <mlx.h>
#include <stdio.h>

typedef struct	s_program
{
	void *mlx;
	void *win;
}	 t_program;


int mouse_event(int button, int x, int y, void *param)
{
	t_program *tutorial = param;

	printf("Button = %d, x = %d, y = %d,  %p\n", button, x, y, param);
	mlx_pixel_put(tutorial->mlx, tutorial->win, x, y, 0xFFFFFF);
	return (1);
}

int main(void)
{
	void *mlx;
	void *win;
	t_program tutorial;

  
	mlx = mlx_init();
 	win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Events params");
	tutorial.mlx = mlx;
    tutorial.win = win;
    mlx_mouse_hook(win, &mouse_event, &tutorial);
    mlx_loop(mlx);
	return (0);
}
