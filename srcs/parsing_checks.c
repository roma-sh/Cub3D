
#include "../cub3d.h"

/*
Check if number of arguments passed to the program is correct
check if the file is ".cub" type
*/
int	arg_check(int argc, char *arg)
{
	int	argv_len;

	if (argc != 2)
	{
		printf("NOT THE RIGHT AMOUNT OF ARGUMENTS\n");
		exit(EXIT_FAILURE);
	}
	argv_len = ft_strlen(arg);
	if (ft_strncmp(arg + argv_len - 4, ".cub", 5) != 0)
	{
		printf("NOT A MAP\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}

void	ft_setup_temp_map(t_game *game, int x, int y)
{
	int		i;
	int		j;
	char	**temp_map;

	temp_map = malloc(game->height_map * sizeof(char *));
	if (temp_map == NULL)
		ft_error_exit(game, "Error\nMemory allocation failed");
	i = -1;
	while (++i < game->height_map)
	{
		(temp_map)[i] = ft_strdup(game->map[i]);
		if ((temp_map)[i] == NULL)
		{
			j = -1;
			while (++j < i)
				free((temp_map)[j]);
			free(temp_map);
			ft_error_exit(game, "Error\nMemory allocation failed");
		}
	}
	check_walls(temp_map, x, y, game);
	free_temp(game, temp_map);
}

void	check_walls(char **map, int x, int y, t_game *game)
{
	if (x < 0 || x >= game->height_map
		|| y < 0 || y >= game->width_map + 1)
		return ;
	if (map[x][y] == '1')
		return ;
	if ((map[x][y] == '0' || map[x][y] == '2' || map[x][y] == '3')
		&& ((x - 1 == -1 || y - 1 == -1
		|| x == game->height_map - 1)))
	{
		printf("No closed map!\n");
		exit(EXIT_FAILURE);
	}
	if (map[x][y] == ' ' || game->map[x][y] == '\n')
	{
		printf("No closed map!\n");
		exit(EXIT_FAILURE);
	}
	map[x][y] = '1';
	check_walls(map, x - 1, y, game);
	check_walls(map, x + 1, y, game);
	check_walls(map, x, y - 1, game);
	check_walls(map, x, y + 1, game);
}

int	check_rgb(char *variable, int **color)
{
	int		i;
	char	**c;

	i = 0;
	while (variable[i] == ' ' || isalpha(variable[i]))
		i++;
	c = ft_split(variable + i, ',');
	validate_rgb_count(c);
	*color = ft_malloc(3 * sizeof(int));
	i = 0;
	while (c[i] != NULL)
	{
		(*color)[i] = ft_atoi(c[i]);
		if ((*color)[i] < 0 || (*color)[i] > 255)
		{
			printf("Invalid RGB numbers\n");
			free_split(c);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	free_split(c);
	return (1);
}

void	validate_rgb_count(char **c)
{
	int	count;
	int	i;
	int	flag;

	flag = 0;
	count = 0;
	while (c[count] != NULL)
	{
		i = 0;
		while (c[count][i] != '\0' && !ft_isalpha(c[count][i]))
			i++;
		if (c[count][i] != '\0')
			flag = 1;
		count++;
	}
	if (count + flag != 3)
	{
		printf("Invalid RGB numbers\n");
		free_split(c);
		exit(EXIT_FAILURE);
	}
}
