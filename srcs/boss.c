
#include "../cub3d.h"


void	loops(t_game *game)
{
	mlx_loop_hook(game->mlx, draw, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

void	draw(void *param)
{
	t_game	*game;

	game = param;
	if (game->intro)
		mlx_image_to_window(game->mlx, game->tex.intro, 0, 0);
	else if (game->player.dead)
	{
		mlx_delete_image(game->mlx, game->mlx_img);
		mlx_delete_image(game->mlx, game->tex.weapon);
		mlx_image_to_window(game->mlx, game->tex.gameover, 0, 0);
	}
	else
	{
		mlx_delete_image(game->mlx, game->tex.intro);
		draw_sky_ground(game);
	}
}
