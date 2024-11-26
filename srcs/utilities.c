
#include "../cub3d.h"

void	ft_error_exit(t_game *game, const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	if (game->mlx)
		mlx_terminate(game->mlx);
	finish(game);
	exit(EXIT_FAILURE);
}
void	free_temp(t_game *game, char **temp)
{
	int	i;

	i = 0;
	while (i < game->height_map)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

void	ft_error_tex(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	finish(t_game *game)
{
	free_map(game);
	delete_texs(game);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height_map)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game->c);
	free(game->f);
	free(game->so);
	free(game->no);
	free(game->we);
	free(game->ea);
}

void	delete_texs(t_game *game)
{
	int	i;

	i = 0;
	mlx_delete_image(game->mlx, game->tex.north_image);
	mlx_delete_image(game->mlx, game->tex.south_image);
	mlx_delete_image(game->mlx, game->tex.west_image);
	mlx_delete_image(game->mlx, game->tex.east_image);
	mlx_delete_image(game->mlx, game->tex.door);
	mlx_delete_image(game->mlx, game->tex.fire);
	mlx_delete_image(game->mlx, game->tex.intro);
	mlx_delete_image(game->mlx, game->tex.heal_0);
	mlx_delete_image(game->mlx, game->tex.heal_1);
	mlx_delete_image(game->mlx, game->tex.crosshair);
	mlx_delete_image(game->mlx, game->tex.weapon);
	mlx_delete_image(game->mlx, game->tex.gameover);
	mlx_delete_image(game->mlx, game->tex.black_hole);
	while (i < 21)
		mlx_delete_image(game->mlx, game->tex.fire_flame[i++]);
}

void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	pixel_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	reset_rays(t_game *game, int *flag)
{
	game->ray.hor_distance = 100000;
	game->ray.ver_distance = 100000;
	game->ray.rx = 0;
	game->ray.ry = 0;
	game->ray.rx_step = 0;
	game->ray.ry_step = 0;
	game->ray.hor_x = 0;
	game->ray.hor_y = 0;
	game->ray.ver_x = 0;
	game->ray.ver_y = 0;
	*flag = 0;
	game->rend.hor_is_door = false;
	game->rend.ver_is_door = false;
	game->rend.hor_is_fire = false;
	game->rend.ver_is_fire = false;
	game->rend.hor_is_flame = false;
	game->rend.ver_is_flame = false;
}
