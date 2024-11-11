
#include "../cub3d.h"

void	init_game(t_game *game)
{
	init_map(game);
	init_player(game);
}

void	init_map(t_game *game)
{
	game->map_unit_size = 64;
	game->map_unit_x = 30;
	game->map_unit_y = 16;
	game->name = "CUB3D";
	game->window_height = 960;
	game->window_width = 1440;
	game->frame_count = 0;
	game->frame_count2 = 0;
}

void	init_player(t_game *game)
{
	game->player.x_player = game->start_pos[1] * 64 + 32; // +32 = 64/2 to put it in the middle of his block
	game->player.y_player = game->start_pos[0] * 64 + 32; // +32 teh same for y axe
	// set the player initial direction depening on the map info
	if (game->orientation == 'N')
		game->player.angle_player = (3 * PI / 2);
	else if (game->orientation == 'S')
		game->player.angle_player = PI / 2;
	else if (game->orientation == 'E')
		game->player.angle_player = 0;
	else if (game->orientation == 'W')
		game->player.angle_player = PI;
	game->player.dx_player = cos (game->player.angle_player) * 5;
	game->player.dy_player = sin (game->player.angle_player) * 5;
	game->player.health = 300;
	game->intro = true; // to start the game with the intro picture
	game->player.dead = false; // if the payer dead we will set this to true which will stop the game
}
