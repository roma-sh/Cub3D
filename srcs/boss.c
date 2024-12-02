
#include "../cub3d.h"


void	loops(t_game *game)
{
	mlx_loop_hook(game->mlx, draw, game);
	mlx_loop_hook(game->mlx, keyboard_control, game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_cursor_hook(game->mlx, mouse_move, game);
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
		calculate_ray(game);
		draw_minimap(game);
		draw_miniplayer(game);
		draw_cross(game);
		draw_weapon(game);
		check_fire(game);
		draw_health(game);
		game->frame_count2++;
	}
}

void	calculate_ray(t_game *game)
{
	int	r_num;
	int	dof;
	int	flag;

	r_num = 0;
	game->ray.ra = game->player.angle_player - 0.523598;
	while (r_num < 1440)
	{
		dof = 0;
		reset_rays(game, &flag);
		calculate_horizontal_intraction(game, &dof);
		get_hor_point(game, dof);
		dof = 0;
		calculate_vertical_intraction(game, &dof, &flag);
		get_ver_point(game, dof);
		get_wall(game, flag);
		render_walls(game, r_num);
		game->ray.ra += 0.01745329 / 24;
		r_num++;
	}
}
