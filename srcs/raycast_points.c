
#include "../cub3d.h"

void	get_hor_point(t_game *game, int dof)
{
	while (dof < 25)
	{
		game->ray.map_index_x = (int)(game->ray.rx) / 64 ;
		game->ray.map_index_y = (int)(game->ray.ry) / 64 ;
		game->ray.hor_x = game->ray.rx;
		game->ray.hor_y = game->ray.ry;
		game->ray.hor_distance = calculate_dis(game->player.x_player,
				game->player.y_player, game->ray.hor_x, game->ray.hor_y);
		if (game->ray.map_index_x >= 0 && game->ray.map_index_y >= 0
			&& game->ray.map_index_y < game->height_map
			&& game->ray.map_index_x
			< (int)ft_strlen(game->map[game->ray.map_index_y]) - 1)
		{
			if (is_hor_wall(game))
				break ;
			else
			{
				game->ray.rx += game->ray.rx_step;
				game->ray.ry += game->ray.ry_step;
				dof++;
			}
		}
		else
			break ;
	}
}

void	get_ver_point(t_game *game, int dof)
{
	while (dof < 25)
	{
		game->ray.map_index_x = (int)(game->ray.rx) / 64;
		game->ray.map_index_y = (int)(game->ray.ry) / 64;
		game->ray.ver_x = game->ray.rx;
		game->ray.ver_y = game->ray.ry;
		game->ray.ver_distance = calculate_dis(game->player.x_player,
				game->player.y_player, game->ray.ver_x, game->ray.ver_y);
		if (game->ray.map_index_x >= 0 && game->ray.map_index_y >= 0
			&& game->ray.map_index_y < game->height_map
			&& game->ray.map_index_x
			< (int)ft_strlen(game->map[game->ray.map_index_y]) - 1)
		{
			if (is_ver_wall(game))
				break ;
			else
			{
				game->ray.rx += game->ray.rx_step;
				game->ray.ry += game->ray.ry_step;
				dof++;
			}
		}
		else
			break ;
	}
}

