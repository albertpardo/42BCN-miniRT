/*
 * https://harm-smits.github.io/42docs/libs/minilibx/events.html
 *
 * Puts X, Y on the cli when the mouse move. 
 * The coordenates apears on cli when the screen is great than the program windows
 */

#include <mlx.h>
#include <stdio.h>

#define MAX_X 500
#define MAX_Y 500


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	pos(int x, int y, t_vars *vars)
{
	printf("(%d, %d), %p\n", x, y, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, MAX_X, MAX_Y, "Mouse Move");
	mlx_hook(vars.win, 6, 0 , pos, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
