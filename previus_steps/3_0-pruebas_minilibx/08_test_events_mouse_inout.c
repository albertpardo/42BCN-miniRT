/*
 * https://harm-smits.github.io/42docs/libs/minilibx/events.html
 */

#include <mlx.h>
#include <stdio.h>

#define MAX_X 500
#define MAX_Y 500


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	in(int x, int y, t_vars *vars)
{
	printf("-(%d, %d), %p\n", x, y, vars->win);
	printf("-Hi\n");
	return (0);
}

int	out(int x, int y, t_vars *vars)
{
	printf(">(%d, %d), %p\n", x, y, vars->win);
	printf(">Bye Bye\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;
// No va bien

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, MAX_X, MAX_Y, "Mouse In/Out Windows");
	mlx_hook(vars.win, 7, 1L<<4, in, &vars); //Focus In
	mlx_loop(vars.mlx);
	return (0);
}
