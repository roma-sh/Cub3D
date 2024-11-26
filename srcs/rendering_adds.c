#include "../cub3d.h"


bool	checker(t_game *game)
{
	if ((game->rend.hor_is_fire)
		&& (game->ray.hor_distance < game->ray.ver_distance))
		return (true);
	else if ((game->rend.ver_is_fire)
		&& (game->ray.hor_distance > game->ray.ver_distance))
		return (true);
	return (false);
}
