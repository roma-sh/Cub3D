
#include "../cub3d.h"

void	draw_tiles(t_game *game, int xo, int yo, uint32_t tile_color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			mlx_put_pixel(game->mlx_img, xo + j, yo + i, tile_color);
			j++;
		}
		i++;
	}
}

void	get_map_index(t_game *game, int *map_index_x, int *map_index_y)
{
	*map_index_x = (game->player.x_player - 32) / 64 - 4;
	*map_index_y = (game->player.y_player - 32) / 64 - 4;
	if (*map_index_x < 0)
		*map_index_x = 0;
	if (*map_index_y < 0)
		*map_index_y = 0;
}

void	get_tile_color(t_game *game, uint32_t *tile_color, int x, int y)
{
	if (game->ray.map_index_y + y < game->height_map && game->ray.map_index_x
		+ x < (int)ft_strlen(game->map[game->ray.map_index_y + y]))
	{
		if (game->map[game->ray.map_index_y + y]
			[game->ray.map_index_x + x] == '1')
			*tile_color = pixel_color(70, 250, 255, 100);
		else if (game->map[game->ray.map_index_y + y]
			[game->ray.map_index_x + x] == '0')
			*tile_color = pixel_color(255, 255, 255, 150);
		else if (game->map[game->ray.map_index_y + y]
			[game->ray.map_index_x + x] == '2')
			*tile_color = pixel_color(0, 150, 100, 255);
		else if (game->map[game->ray.map_index_y + y]
			[game->ray.map_index_x + x] == '3')
			*tile_color = pixel_color(255, 0, 0, 100);
		else if (game->map[game->ray.map_index_y + y]
			[game->ray.map_index_x + x] == ' '
			|| game->map[game->ray.map_index_y + y]
			[game->ray.map_index_x + x] == '\n')
			*tile_color = pixel_color(0, 0, 0, 255);
		else
			*tile_color = pixel_color(255, 255, 255, 150);
	}
	else
		*tile_color = pixel_color(0, 0, 0, 255);
}

void	draw_minimap(t_game *game)
{
	int			y;
	int			x;
	uint32_t	tile_color;

	get_map_index(game, &game->ray.map_index_x, &game->ray.map_index_y);
	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			get_tile_color(game, &tile_color, x, y);
			draw_tiles(game, x * 32, y * 32, tile_color);
			x++;
		}
		y++;
	}
}

void	draw_miniplayer(t_game *game)
{
	int	point1[2];
	int	map_index_x;
	int	map_index_y;

	get_map_index(game, &map_index_x, &map_index_y);
	point1[0] = (game->player.x_player) / 64 - map_index_x;
	point1[1] = (game->player.y_player) / 64 - map_index_y;
	point1[0] *= 32;
	point1[1] *= 32;
	draw_tiles(game, point1[0], point1[1], pixel_color(255, 0, 0, 255));
	point1[0] += 16;
	point1[1] += 16;
	draw_line(game, point1, point1[0] + 41
		* cos(game->player.angle_player), point1[1] + 41
		* sin(game->player.angle_player));
}

void	draw_line(t_game *game, int *point1, int x1, int y1)
{
	int			d[2];
	int			err[2];
	int			point2[2];

	point2[0] = x1;
	point2[1] = y1;
	d[0] = abs(x1 - point1[0]);
	d[1] = abs(y1 - point1[1]);
	err[0] = d[0] - d[1];
	while (1)
	{
		mlx_put_pixel(game->mlx_img, point1[0], point1[1],
			pixel_color(255, 0, 0, 255));
		if (point1[0] == x1 && point1[1] == y1)
			break ;
		get_next_ponit(point1, d, err, point2);
	}
}

void	get_next_ponit(int *point1, int *d, int *err, int *point2)
{
	err[1] = err[0] * 2;
	if (err[1] > -d[1])
	{
		err[0] -= d[1];
		if (point1[0] < point2[0])
			point1[0] += 1;
		else
			point1[0] -= 1;
	}
	if (err[1] < d[0])
	{
		err[0] += d[0];
		if (point1[1] < point2[1])
			point1[1] += 1;
		else
			point1[1] -= 1;
	}
}
