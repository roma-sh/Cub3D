
#include "../cub3d.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init(1440, 960, "CUB3D", false);
	if (!game->mlx)
		return (1);
	game->mlx_img = mlx_new_image(game->mlx, 1440, 960);
	if (!game->mlx_img)
	{
		mlx_close_window(game->mlx);
		return (1);
	}
	if (mlx_image_to_window(game->mlx, game->mlx_img, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		return (1);
	}
	return (0);
}
