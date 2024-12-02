
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

enum e_channel
{
	ALPHA,
	RED,
	GREEN,
	BLUE,
};

typedef union s_color
{
	uint8_t		channel[4];
	uint32_t	color;
}			t_color;

typedef struct s_rend
{
	float		wall_distance;
	float		wall_x;
	float		wall_y;
	float		texture_pos_x_rate;
	uint32_t	texture_x;
	uint32_t	texture_y;
	mlx_image_t	*current_texture;
	float		wall_height;
	bool		hor_is_door;
	bool		ver_is_door;
	bool		hor_is_fire;
	bool		ver_is_fire;
	bool		hor_is_flame;
	bool		ver_is_flame;

}			t_rend;

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

typedef struct s_raycast
{
	float		rx;
	float		ry;
	float		ra;
	float		rx_step;
	float		ry_step;
	float		hor_distance;
	float		hor_x;
	float		hor_y;
	float		ver_distance;
	float		ver_x;
	float		ver_y;
	int			map_index_x;
	int			map_index_y;

}			t_raycast;

typedef struct s_player
{
	float			x_player;
	float			y_player;
	float			dx_player;
	float			dy_player;
	float			angle_player;
	float			start_angle;
	int				mouse_pos;
	int				health;
	bool			dead;
}	t_player;

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
	int				window_width;
	int				window_height;
	int				map_unit_x;
	int				map_unit_y;
	int				map_unit_size;
	int				frame_count;
	int				frame_count2;
	const char		*name;
	t_player		player;
	bool			intro;
	t_raycast		ray;
	t_rend			rend;


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
int		is_only_spaces(char *str);
void	ft_setup_temp_map(t_game *game, int x, int y);
void	check_walls(char **map, int x, int y, t_game *game);
int		check_rgb(char *variable, int **color);
void	validate_rgb_count(char **c);

// Initializations of mlx:
int	init_mlx(t_game *game);

// Initializations of game:
void	init_game(t_game *game);
void	init_player(t_game *game);
void	init_map(t_game *game);

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
void	ft_error(void);

// Finish game:
void	finish(t_game *game);
void	free_map(t_game *game);
void	delete_texs(t_game *game);

// Drawing:
void	draw(void *param);
void	draw_sky_ground(t_game *game);
int32_t	pixel_color(int r, int g, int b, int a);
uint32_t	get_color(uint32_t	texture_color);

//Calculations:
void	calculate_ray(t_game *game);
void	reset_rays(t_game *game, int *flag);
void	calculate_vertical_intraction(t_game *game, int *dof, int *flag);
void	calculate_horizontal_intraction(t_game *game, int *dof);
void	get_hor_point(t_game *game, int dof);
void	get_ver_point(t_game *game, int dof);
void	get_wall(t_game *game, int flag);
void	set_hor_tex(t_game *game);
void	set_ver_tex(t_game *game);
void	fix_fisheye(t_game *game);
float	calculate_dis(float x1, float y1, float x2, float y2);
bool	is_ver_wall(t_game *game);
bool	is_hor_wall(t_game *game);

// Rendering:
void	render_walls(t_game *game, int r_num);
bool	animate_fire(t_game *game, int r_num);
void	draw_tex_slice(t_game *game, int shift_to_down, int r_num, int offset);
void	draw_far_slice(t_game *game, int r_num, int shift_to_down);
void	draw_close_slice(t_game *game, int r_num, int offset);
bool	checker(t_game *game);
void	draw_cross(t_game *game);
void	draw_weapon(t_game *game);
void	check_fire(t_game *game);
void	draw_health(t_game *game);
void	draw_health_section(t_game *game, mlx_image_t *heal, int x, int y);

// Movement:
void	keyboard_control(void *param);
void	sw(t_game *game);
void	ad(t_game *game);
void	left_right(t_game *game);
void	coordinate_corrector(t_game *game, char c);
void	coordinate_corrector2(t_game *game, char c);
void	mouse_move(double x, double y, void *param);

// Mini map:
void	draw_minimap(t_game *game);
void	get_map_index(t_game *game, int *map_index_x, int *map_index_y);
void	get_tile_color(t_game *game, uint32_t *tile_color, int x, int y);
void	draw_miniplayer(t_game *game);
void	draw_tiles(t_game *game, int xo, int yo, uint32_t tile_color);
void	draw_line(t_game *game, int *point1, int x1, int y1);
void	get_next_ponit(int *point1, int *d, int *err, int *point2);

// Finishing the game:
void	finish(t_game *game);
void	delete_texs(t_game *game);
void	free_map(t_game *game);

#endif
