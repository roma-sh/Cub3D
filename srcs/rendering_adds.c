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

void	draw_weapon(t_game *game)
{
	mlx_image_to_window(game->mlx, game->tex.weapon,
		game->window_width - 650, game->window_height - 312);
}

void	draw_cross(t_game *game)
{
	draw_health_section(game, game->tex.crosshair,
		game->window_width / 2 - 30, game->window_height / 2 - 30);
}

void	check_fire(t_game *game)
{
	int	i;
	int	j;
	int	red_intensity;

	j = 0;
	if (game->map[(int)(game->player.y_player) / 64]
			[(int)(game->player.x_player) / 64] == '3')
	{
		red_intensity = 150 + (sin(game->frame_count * 0.2) * 50);
		while (j++ < game->window_width - 1)
		{
			i = 0;
			while (i++ < game->window_height - 1)
			{
				if (i % 2 == 1)
					mlx_put_pixel(game->mlx_img, j, i,
						pixel_color(red_intensity, 0, 0, 150));
			}
		}
		game->player.health--;
		game->frame_count++;
	}
	if (game->player.health < 15)
		game->player.dead = true;
}

void	draw_health_section(t_game *game, mlx_image_t *heal, int x, int y)
{
	uint32_t	m;
	uint32_t	n;
	uint32_t	texture_color;

	m = 0;
	while (m < heal->height)
	{
		n = 0;
		while (n < heal->width)
		{
			texture_color = ((uint32_t *)heal->pixels)[m * heal->width + n];
			if (texture_color >= 1000000000)
				mlx_put_pixel(game->mlx_img,
					x + n, y + m, get_color(texture_color));
			n++;
		}
		m++;
	}
}

void	draw_health(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->player.health / 15)
	{
		draw_health_section(game, game->tex.heal_1, (1020 + (i * 20)), 20);
		i++;
	}
	while (i < 20)
	{
		draw_health_section(game, game->tex.heal_0, (1020 + (i * 20)), 20);
		i++;
	}
}
