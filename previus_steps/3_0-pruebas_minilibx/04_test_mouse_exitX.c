/* 
 * Code  based on: 
 * https://gontjarow.github.io/MiniLibX/mlx-tutorial-register-event-handlers.html 
 *
 * And (for Exit using `mlx_hook`) : 
 * https://pulgamecanica.herokuapp.com/posts/minilibx-tutorial
 */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_X 640
#define MAX_Y 360

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

int	mouse_event(int button, int x, int y, void *win)
{
	printf("Button = %d, x = %d, y = %d,  %p\n", button, x, y, win);
	return (0);
}

int	exit_x(t_win *win)
{
	mlx_destroy_window (win->mlx_ptr, win->win_ptr);
	exit(0);  // Close Windows and finish the program`
	return(0);
}

t_win start_newindow(int w, int h, char *str)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, w, h, str);
	return ((t_win) {mlx_ptr, win_ptr, w, h});
}

int main(void)
{
 	t_win	win;

	win = start_newindow(MAX_X, MAX_Y, "Mouse can press 'X' to Close actual Window");
	if (win.mlx_ptr != NULL && win.win_ptr != NULL)
	{
		mlx_mouse_hook(win.win_ptr, &mouse_event, (void *) 0);
		mlx_hook(win.win_ptr, 17, 1L<<0, &exit_x, &win);
   		mlx_loop(win.mlx_ptr);
	}
	else
		return (1);
	return (0);
}
