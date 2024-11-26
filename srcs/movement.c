#include "../cub3d.h"

void	keyboard_control(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
	{
		game->player.dx_player = cos (game->player.angle_player) * 17;
		game->player.dy_player = sin (game->player.angle_player) * 17;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_SPACE))
		game->intro = false;
	sw(game);
	ad(game);
	left_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		finish(game);
		exit(1);
	}
}

void	sw(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		if (!mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
		{
			game->player.dx_player = cos (game->player.angle_player) * 5;
			game->player.dy_player = sin (game->player.angle_player) * 5;
		}
		game->player.y_player += game->player.dy_player;
		game->player.x_player += game->player.dx_player;
		coordinate_corrector(game, 'W');
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		if (!mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
		{
			game->player.dx_player = cos (game->player.angle_player) * 5;
			game->player.dy_player = sin (game->player.angle_player) * 5;
		}
		game->player.y_player -= game->player.dy_player;
		game->player.x_player -= game->player.dx_player;
		coordinate_corrector(game, 'S');
	}
}

void	ad(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		game->player.x_player += cos(game->player.angle_player - PI / 2) * 7;
		game->player.y_player += sin(game->player.angle_player - PI / 2) * 7;
		coordinate_corrector2(game, 'A');
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		game->player.x_player += cos(game->player.angle_player + PI / 2) * 7;
		game->player.y_player += sin(game->player.angle_player + PI / 2) * 7;
		coordinate_corrector2(game, 'D');
	}
}

void	left_right(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->player.angle_player -= 0.05;
		if (game->player.angle_player < 0)
			game->player.angle_player += 2 * PI;
		game->player.dx_player = cos (game->player.angle_player) * 5;
		game->player.dy_player = sin (game->player.angle_player) * 5;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->player.angle_player += 0.05;
		if (game->player.angle_player > 2 * PI)
			game->player.angle_player -= 2 * PI;
		game->player.dx_player = cos (game->player.angle_player) * 5;
		game->player.dy_player = sin (game->player.angle_player) * 5;
	}
}


void	coordinate_corrector(t_game *game, char c)
{
	if (game->map[((int)game->player.y_player) / 64]
		[((int)game->player.x_player) / 64] == '1')
	{
		if (c == 'W')
		{
			game->player.y_player -= game->player.dy_player;
			game->player.x_player -= game->player.dx_player;
		}
		else if (c == 'S')
		{
			game->player.y_player += game->player.dy_player;
			game->player.x_player += game->player.dx_player;
		}
	}
}

void	coordinate_corrector2(t_game *game, char c)
{
	if (game->map[((int)game->player.y_player) / 64]
		[((int)game->player.x_player) / 64] == '1')
	{
		if (c == 'A')
		{
			game->player.x_player += cos(game->player.angle_player
					+ PI / 2) * 7;
			game->player.y_player += sin(game->player.angle_player
					+ PI / 2) * 7;
		}
		else if (c == 'D')
		{
			game->player.x_player -= cos(game->player.angle_player
					+ PI / 2) * 7;
			game->player.y_player -= sin(game->player.angle_player
					+ PI / 2) * 7;
		}
	}
}
