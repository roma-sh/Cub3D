
#include "../cub3d.h"


// initialize the mlx library:
// game:mlx: Main MLX handle, carries important data in regards to the program.
// game:mlx_img: An image with an individual buffer that can be rendered.
/*
typedef struct mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t*	instances;
	int32_t			count;
	bool			enabled;
	void*			context;
}	mlx_image_t;
*/
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
