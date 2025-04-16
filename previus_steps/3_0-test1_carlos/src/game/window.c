
#include "window.h"
#include "cub3d.h"


// /*Funcion que inicializa minilibx, crea una ventana*/
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_errors2(5);
	game->mlx_win = mlx_new_window(game->mlx, 40 * TILE_PXL, 40 * TILE_PXL, "cub3D");
	//printf("W: %d\n H: %d", game->w, game->h);
}
