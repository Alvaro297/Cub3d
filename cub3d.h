#ifndef CUB3D_H
# define CUB3D_H

# include "./libft_cub3d/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"

typedef enum s_color
{
	RED,
	GREEN,
	BLUE,
}				t_color;

typedef enum e_parse_state
{
	PARSE_TEXTURES,
	PARSE_COLORS,
	PARSE_MAP
}	t_parse_state;

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
	t_parse_state	parse;
}				t_map;

typedef struct s_player
{
	double			x_position;
	double			y_position;
	char			direction;
	double			angle;
	int				player_count;
	void			*img;
}				t_player;

typedef struct s_cub3d
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*map_route;
	t_map		map;
	t_player	player;
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
void			validate_textures(t_cub3d *cub3d);
int				check_texture_file(const char *path);
int				check_texture_name(const char *path, const char *expected);
void			validate_config(t_cub3d *cub3d);
void			free_cub3d(t_cub3d *cub3d);
void			ft_free_map(char **map_lines, t_cub3d *cub3d);
int				is_blank_line(char *line);
int				handle_map_line(char *line, t_cub3d *cub3d, char **map_lines);

#endif