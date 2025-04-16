
#include "cub3d.h"
#include "window.h"

int	open_map2(char *av, t_game *game)
{
	game->map_fd = open(av, O_RDONLY);
	if (game->map_fd == -1)
		write(2, "Error\nIt was not possible to open the file\n", 42);
	return (0);
}

void	create_matrix(t_game *game, char *av)
{
	int	i;

	i = 0;
	open_map2(av, game);
	game->matrix = (char **)malloc(sizeof(char *) * (game->h + 1));
	if (!game->matrix)
		return ;
	while (i < game->h)
	{
		game->matrix[i] = get_next_line(game->map_fd);
		i++;
	}
	game->matrix[game->h] = NULL;
	close(game->map_fd);
}


int	main(int ac, char *av[])
{
	t_game	game;

	if (ac == 2)
	{
		open_map2(av[1], &game);
		create_matrix(&game, av[1]);
		init_game(&game);
		mlx_hook(game.mlx_win, X_EVENT_KEY_PRESS, 0, &press_key, &game);
		mlx_hook(game.mlx_win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
		mlx_loop(game.mlx);
	}
	else
		write(2, "Error...\n", 9);
	return (0);
}
