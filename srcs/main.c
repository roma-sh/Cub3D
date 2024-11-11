
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
	return (0);
}
