
#include "../cub3d.h"

void	init_game(t_game *game)
{
	init_map(game);
	init_player(game);
}

void	loops(t_game *game)
{
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
