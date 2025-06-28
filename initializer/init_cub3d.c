#include "./cub3d.h"

static t_map	init_map()
{
	t_map	map;

	map.matriz = NULL;
	map.n_players = 0;
	map.n_wall = 0;
	map.rgb_celling = NULL;
	map.rgb_floor = NULL;
	return (map);
}

static t_player	init_player()
{
	t_player	player;

	player.img = NULL;
	player.x_position = 0;
	player.y_position = 0;
	return (player);
}

void		init_cub3d(t_cub3d *cub3d)
{
	cub3d->mlx_ptr = mlx_init();
	cub3d->win_ptr = mlx_new_window(cub3d->mlx_ptr, 1280, 720, "Cub3d");
	cub3d->img_ptr = mlx_new_image(cub3d->mlx_ptr, 1280, 720);
	cub3d->map = init_map();
	cub3d->player = init_player();
}
