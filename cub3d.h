#ifndef CUB3D_H
# define CUB3D_H

# include "./libft_cub3d/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdbool.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

typedef enum s_color
{
	RED,
	GREEN,
	BLUE,
}				t_color;

typedef struct s_map
{
	char		**matriz;
	int			n_wall;
	int			n_players;
	int			count_textures;
	int			rgb_floor[3];
	int			rgb_ceiling[3];
	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	char		*tex_ea;
	int			map_index;
	t_color		colors;
}				t_map;

typedef struct s_player
{
	double		x_position;
	double		y_position;
	char		direction;
	double		angle;
	int			player_count;
	double		direccion_x;
	double		direccion_y;
	void		*img;
}				t_player;

typedef struct s_raycasting
{
	double	*delta_dist_x;
	double	*delta_dist_y;
	double	*raydir_x;
	double	*raydir_y;
	double	*sideDist_x;
	double	*sideDist_y;
	short	*step_x;
	short	*step_y;
	bool	*is_horizontal;
	double	*perp_wall_dist;
	double	*wall_hit_x;
	double	*wall_hit_y;
	char	*hit_type;
}				t_raycasting;

typedef struct s_cub3d
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*map_route;
	t_map			map;
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
int				is_closed(char **map, int x, int y);
void			validate_map(t_cub3d *cub3d);
void			validate_config(t_cub3d *cub3d);
void			free_cub3d(t_cub3d *cub3d);
void			ft_free_map(char **map_lines, t_cub3d *cub3d);

//** Raycasting **//
void			init_raycasting(t_cub3d *cub3d);
void			steps(t_cub3d *cub3d);
void			free_raycast(t_cub3d *cub3d);
void			reinit_raycast(t_cub3d *cub3d);
void			dda_algorithm(t_cub3d *cub3d)
#endif