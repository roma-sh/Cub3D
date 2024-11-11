
#include "../cub3d.h"

/*
fill the window with two colors, the sky
color and the ground color which we take them from the
map file
it will also print a random stars on the sky to give a
galaxy effect
mlx_put_pixel is used to draw a specific color to
a specific coordinates on the mlx_img image which is
already sent to the window
*/
void	draw_sky_ground(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->window_width)
	{
		j = 0;
		while (j < game->window_height)
		{
			if (j <= game->window_height / 2 - 30)
			{
				mlx_put_pixel(game->mlx_img, i, j, pixel_color(game->c[0],
						game->c[1], game->c[2], 180));
				if (rand() % 10000 < 2)
					mlx_put_pixel(game->mlx_img, i, j,
						pixel_color(255, 255, 255, 255));
			}
			else
				mlx_put_pixel(game->mlx_img, i, j, pixel_color(game->f[0],
						game->f[1], game->f[2], 60));
			j++;
		}
		i++;
	}
}
