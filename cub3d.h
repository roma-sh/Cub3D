
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include "Get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"

# define PI 3.1415926535


typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*mlx_img;
}	t_game;

// Parsing
int	arg_check(int argc, char *arg);

// Initializations:
int	init_mlx(t_game *game);

// Proccessing:
void	loops(t_game *game);
#endif
