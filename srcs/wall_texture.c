
#include "../cub3d.h"


void	get_wall(t_game *game, int flag)
{
	game->rend.wall_distance = 0;
	game->rend.current_texture = NULL;
	if (game->ray.ver_distance < game->ray.hor_distance)
	{
		set_ver_tex(game);
		game->rend.wall_distance = game->ray.ver_distance;
		game->rend.wall_x = game->ray.ver_x;
		game->rend.wall_y = game->ray.ver_y;
	}
	else if (game->ray.ver_distance >= game->ray.hor_distance)
	{
		set_hor_tex(game);
		game->rend.wall_distance = game->ray.hor_distance;
		game->rend.wall_x = game->ray.hor_x;
		game->rend.wall_y = game->ray.hor_y;
	}
	if ((flag == 1) && !game->rend.hor_is_door
		&& !game->rend.hor_is_fire)
		game->rend.current_texture = game->tex.south_image;
	fix_fisheye(game);
}

void	set_ver_tex(t_game *game)
{
	bool	temp_is_door;

	temp_is_door = game->rend.ver_is_door;
	if (game->rend.ver_is_door && game->ray.ver_distance < 80)
		temp_is_door = false;
	if (temp_is_door)
		game->rend.current_texture = game->tex.door;
	else if (game->rend.ver_is_fire)
		game->rend.current_texture = game->tex.fire;
	else if (!game->rend.ver_is_door)
	{
		if (game->ray.rx > game->player.x_player)
			game->rend.current_texture = game->tex.east_image;
		else
			game->rend.current_texture = game->tex.west_image;
	}
	else
		game->rend.current_texture = game->tex.black_hole;
}

void	set_hor_tex(t_game *game)
{
	bool	temp_is_door;

	temp_is_door = game->rend.hor_is_door;
	if (game->rend.hor_is_door && game->ray.hor_distance < 80)
		temp_is_door = false;
	if (temp_is_door)
		game->rend.current_texture = game->tex.door;
	else if (game->rend.hor_is_fire)
		game->rend.current_texture = game->tex.fire;
	else if (!game->rend.hor_is_door)
	{
		if (game->ray.ry > game->player.y_player)
			game->rend.current_texture = game->tex.south_image;
		else
			game->rend.current_texture = game->tex.north_image;
	}
	else
		game->rend.current_texture = game->tex.black_hole;
}

void	fix_fisheye(t_game *game)
{
	float	fish_eye;

	fish_eye = game->player.angle_player - game->ray.ra;
	if (fish_eye < 0)
		fish_eye += 2 * PI;
	if (fish_eye > 2 * PI)
		fish_eye -= 2 * PI;
	game->rend.wall_distance = game->rend.wall_distance * cos(fish_eye);
}
