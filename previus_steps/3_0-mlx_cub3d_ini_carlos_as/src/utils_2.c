
#include "cub3d.h"
#include "window.h"

int	exit_game(t_game *g)
{
	write (1, "####################\n", 21);
	write (1, "     End Game!\n", 15);
	write (1, "####################\n", 21);
	mlx_destroy_window(g->mlx, g->mlx_win);
	free(g->mlx);
	exit(0);
}

int	press_key(int keycode, t_game *game)
{
	(void)game;
	printf("Keycode: %d\n", keycode);
	return (0);
}


