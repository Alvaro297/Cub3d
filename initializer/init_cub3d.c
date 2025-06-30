#include "./cub3d.h"

static t_map	init_map(void)
{
	t_map	map;

	map.matriz = NULL;
	map.n_players = 0;
	map.n_wall = 0;
	map.rgb_floor[0] = -1;
	map.rgb_floor[1] = -1;
	map.rgb_floor[2] = -1;
	map.rgb_ceiling[0] = -1;
	map.rgb_ceiling[1] = -1;
	map.rgb_ceiling[2] = -1;
	map.tex_no = NULL;
	map.tex_so = NULL;
	map.tex_we = NULL;
	map.tex_ea = NULL;
	return (map);
}

static t_player	init_player(void)
{
	t_player	player;

	player.img = NULL;
	player.x_position = 0;
	player.y_position = 0;
	return (player);
}

void	init_cub3d(t_cub3d *cub3d)
{
	/* cub3d->mlx_ptr = mlx_init();
	cub3d->win_ptr = mlx_new_window(cub3d->mlx_ptr, 1280, 720, "Cub3d");
	cub3d->img_ptr = mlx_new_image(cub3d->mlx_ptr, 1280, 720); */
	cub3d->map = init_map();
	cub3d->player = init_player();
}
