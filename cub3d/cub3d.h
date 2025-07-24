#ifndef CUB3D_H
# define CUB3D_H

# include "./libft_cub3d/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdbool.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define GREY 0xAAAAAA
#define RED2 0xFF0000
#define GREEN2 0x00FF00
#define BLUE2 0x0000FF
#define YELLOW 0xFFFF00
#define BLACK 0x444444

typedef struct s_map
{
	char		**matriz;
	char		**matriz_norm;
	int			n_wall;
	int			n_players;
	int			count_textures;
	int			count_rgb;
	int			floor;
	int			ceiling;
	int			rgb_floor[3];
	int			rgb_ceiling[3];
	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	char		*tex_ea;
	int			height;
	int			width;
	int			map_index;
	int			parse;
	int			map_scale;
}				t_map;

typedef struct s_movement
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}	t_movement;


typedef struct s_player
{
	double		x_position;
	double		y_position;
	char		direction;
	double		angle;
	int			player_count;
	double		direccion_x;
	double		direccion_y;
	t_movement	movement;
	void		*img;
}				t_player;

typedef struct s_raycasting
{
	double	delta_dist_x;
	double	delta_dist_y;
	double	raydir_x;
	double	raydir_y;
	double	sideDist_x;
	double	sideDist_y;
	short	step_x;
	short	step_y;
	bool	is_horizontal;
	double	perp_wall_dist;
	double	wall_hit_x;
	double	wall_hit_y;
	char	hit_type;
}				t_raycasting;


typedef struct s_image
{
	void	*img_ptr;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_cub3d
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*map_route;
	t_map			map;
	t_image			image;
	t_player		player;
	t_raycasting	raycast;
}				t_cub3d;

int				main(int argc, char **argv);
void			init_cub3d(t_cub3d *cub3d);
void			check_name(char *filename);
void			read_map(char *filename, t_cub3d *cub3d);
void			ft_freedom(char **str);
int				coun_lines(char *filename);
int				is_line(char *line);
int				check_rgb(char *str, int rgb[3]);
void			set_player(t_cub3d *cub3d, int x, int y, char dir);
void			validate_map(t_cub3d *cub3d);
void			validate_textures(t_cub3d *cub3d);
int				check_texture_file(const char *path);
int				check_texture_name(const char *path);
void			validate_config(t_cub3d *cub3d);
void			free_cub3d(t_cub3d *cub3d);
void			ft_free_map(char **map_lines, t_cub3d *cub3d);
int				is_blank_line(char *line);
void			check_player(t_cub3d *cub3d);
void			validate_cell(t_cub3d *cub3d, char **map_copy,
					int y, int x, int height);
void			free_norm_map(char **map, int upto);
int				handle_map_line(char *line, t_cub3d *cub3d, char **map_lines);
//** Raycasting **//
t_raycasting	init_raycasting(void);
void			starting_raycasting(t_cub3d *cub3d, char pos_player);
void			raycast(t_cub3d *cub3d);
void			steps(t_cub3d *cub3d);
void			dda_loop(t_cub3d *cub3d, int map_x, int map_y);
void			step_direccion(t_cub3d *cub3d, int map_x, int map_y);
//** Print_Cub3d **//
void			print_cub3d(t_cub3d *cub3d, int x);
void			color_floor_ceiling(t_cub3d *cub3d);
//** Buffer Functions **//
void			init_image_buffer(t_cub3d *cub3d);
void			put_pixel_to_buffer(t_cub3d *cub3d, int x, int y, int color);
void			render_buffer_to_window(t_cub3d *cub3d);
void			clear_buffer(t_cub3d *cub3d, int color);
void			render_ceiling_floor(t_cub3d *cub3d);
//** Movement **//
int				ft_key_hook(t_cub3d *cub3d);
int				key_press(int keycode, t_cub3d *cub3d);
int				key_release(int keycode, t_cub3d *cub3d);
void			movement_player(t_cub3d *cub3d);
bool			is_wall(t_cub3d *cub3d, double x, double y);

#endif