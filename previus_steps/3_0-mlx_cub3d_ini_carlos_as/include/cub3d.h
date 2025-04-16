
#ifndef CUB3D_H
# define CUB3D_H

# include "window.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"



typedef struct s_point
{
	int			x;
	int			y;
}	t_point;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**matrix;
	int		map_fd;
	int		w;
	int		h;
	int		q_collec;
	int		collected;
	int		walk_cnt;
}	t_game;

/* ---------------------------- PARSING ----------------------------*/


/* ---------------------------- GAME ----------------------------*/
void	init_game(t_game *game);
int	exit_game(t_game *g);
int	press_key(int keycode, t_game *game);
int	ft_errors2(int n);

#endif
