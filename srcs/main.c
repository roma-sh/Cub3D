
#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_game				game;

	ft_memset(&game, 0, sizeof(t_game));
	arg_check(argc, argv[1]);
	init_mlx(&game);
	map_reader(&game, argv[1]);
	if (game.map == NULL)
		ft_error();
	init_game(&game);
	loops(&game);
	finish(&game);
	return (0);
}

void	finish(t_game *game)
{
	free_map(game);
	delete_texs(game);
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
