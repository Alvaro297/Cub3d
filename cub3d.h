#ifndef CUB3D_H
# define CUB3D_H

# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "./libft_cub3d/libft.h"

typedef struct s_map
{
	char	**matriz;
	int		n_wall;
	int		n_players;
	int		*rgb_floor;
	int		*rgb_celling;
}	t_map;

typedef struct s_player
{
	int		x_position;
	int		y_position;
	void	*img;
}	t_player;


typedef struct s_cub3d
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*map_route;
	t_map		map;
	t_player	player;
}	t_cub3d;

int		main(int argc, char **argv);
void	init_cub3d(t_cub3d *cub3d);

#endif