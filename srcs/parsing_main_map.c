
#include "../cub3d.h"

void	find_map_width(t_game *game)
{
	int	x;
	int	y;
	int	temp;

	y = 0;
	temp = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			x++;
		}
		while (game->map[y][x - 1] == ' ' || game->map[y][x - 1] == '\n')
			x--;
		if (x > temp)
			temp = x;
		y++;
	}
	game->width_map = temp;
}

// find the initial player coordinates
void	find_start_pos(t_game *game)
{
	int	x;
	int	y;
	int	flag;

	y = 0;
	flag = 0;
	game->start_pos = ft_malloc(sizeof(int) * 2);
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (ft_isalpha(game->map[y][x]))
			{
				validate_player_char(game->map[y][x]);
				game->orientation = game->map[y][x];
				game->start_pos[0] = y;
				game->start_pos[1] = x;
				flag++;
			}
			x++;
		}
		y++;
	}
	check_start_pos_flag(flag, game);
}

// check if there is a player in the map
void	check_start_pos_flag(int flag, t_game *game)
{
	if (flag != 1)
	{
		printf("Insufficient characters\n");
		free(game->start_pos);
		exit(EXIT_FAILURE);
	}
}

void	validate_player_char(char c)
{
	if (c != 'N' && c != 'E' && c != 'W' && c != 'S')
	{
		printf("Wrong player character!\n");
		exit(EXIT_FAILURE);
	}
}
//fill the **map from the map file 
void	fill_real_map(t_game *game, char *reader)
{
	int	y;

	y = 0;
	game->map = ft_calloc(200, sizeof(char *));
	while (reader != NULL)
	{
		game->map[y] = ft_strdup(reader);
		free(reader);
		reader = get_next_line(game->map_fd);
		y++;
		game->height_map++;
	}
	y -= 1;
	while (y >= 0)
	{
		if (is_only_spaces(game->map[y]) == 0)
		{
			free(game->map[y]);
			game->map[y] = NULL;
		}
		else
			break ;
		y--;
		game->height_map--;
	}
}
