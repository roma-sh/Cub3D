
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

typedef struct s_texture
{
	mlx_image_t	*north_image;
	mlx_image_t	*south_image;
	mlx_image_t	*west_image;
	mlx_image_t	*east_image;
	mlx_image_t	*door;
	mlx_image_t	*fire;
	mlx_image_t	*intro;
	mlx_image_t	*heal_0;
	mlx_image_t	*heal_1;
	mlx_image_t	*crosshair;
	mlx_image_t	*weapon;
	mlx_image_t	*gameover;
	mlx_image_t	*black_hole;
	mlx_image_t	*fire_flame[21];
}	t_texture;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*mlx_img;
	int				map_fd;
	int				*start_pos;
	char			*so;
	char			*no;
	char			*we;
	char			*ea;
	int				*c;
	int				*f;
	char			orientation;
	char			**map;
	int				width_map;
	int				height_map;
	t_texture		tex;

}	t_game;

// Parsing
int		arg_check(int argc, char *arg);
void	map_reader(t_game *game, char *map);
void	fill_map_variables(t_game *game);
void	process_variable(t_game *game, char *variable, int *i);
int		assign_texture(char **destination, char *variable, char *prefix);
void	check_unique_textures(t_game *game);
void	find_map_width(t_game *game);
void	find_start_pos(t_game *game);
void	validate_player_char(char c);
void	check_start_pos_flag(int flag, t_game *game);
void	fill_real_map(t_game *game, char *reader);
void	check_wall_boarders(int x, int y, t_game *game);
int		is_only_spaces(char *str);
void	ft_setup_temp_map(t_game *game, int x, int y);
void	check_walls(char **map, int x, int y, t_game *game);
int		check_rgb(char *variable, int **color);
void	validate_rgb_count(char **c);

// Initializations:
int	init_mlx(t_game *game);

// Proccessing:
void	loops(t_game *game);

// Textures loading:
void	init_textures(t_game *game);
void	ft_load_image(t_game *game, mlx_image_t **image, const char *file_path);
void	keep_loading(t_game *game);

// Parsing:
void	map_reader(t_game *game, char *map);
void	check_wall_boarders(int x, int y, t_game *game);
int		is_only_spaces(char *str);
void	fill_map_variables(t_game *game);
void	process_variable(t_game *game, char *variable, int *i);
int		assign_texture(char **destination, char *variable, char *prefix);
void	check_unique_textures(t_game *game);
void	find_map_width(t_game *game);
void	find_start_pos(t_game *game);
void	check_start_pos_flag(int flag, t_game *game);
void	validate_player_char(char c);
void	fill_real_map(t_game *game, char *reader);
int	check_for_assign(t_game *game, char *variable);

// Memory manegment:
void	free_temp(t_game *game, char **temp);

// Error handeling
void	ft_error_exit(t_game *game, const char *msg);
void	ft_error_tex(void);

// Finish game:
void	finish(t_game *game);
void	free_map(t_game *game);
void	delete_texs(t_game *game);

#endif
