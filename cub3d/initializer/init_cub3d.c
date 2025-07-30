#include "../cub3d.h"

static t_map	init_map(void)
{
	t_map	map;

	map.matriz = NULL;
	map.matriz_norm = NULL;
	map.n_players = 0;
	map.n_wall = 0;
	map.count_textures = 0;
	map.count_rgb = 0;
	map.floor = 0;
	map.ceiling = 0;
	map.rgb_floor[0] = -1;
	map.map_index = 0;
	map.rgb_floor[1] = -1;
	map.rgb_floor[2] = -1;
	map.rgb_ceiling[0] = -1;
	map.rgb_ceiling[1] = -1;
	map.rgb_ceiling[2] = -1;
	map.tex_no = NULL;
	map.tex_so = NULL;
	map.tex_we = NULL;
	map.tex_ea = NULL;
	map.parse = 0;
	return (map);
}

static t_movement	init_movement(void)
{
	t_movement	move;

	move.w = false;
	move.a = false;
	move.s = false;
	move.d = false;
	move.left = false;
	move.right = false;
	return (move);
}

static t_player	init_player(void)
{
	t_player	player;

	player.x_position = 0;
	player.player_count = 0;
	player.y_position = 0;
	player.movement = init_movement();
	return (player);
}

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->mlx_ptr = NULL;
	cub3d->win_ptr = NULL;
	cub3d->img_ptr = NULL;
	cub3d->map_route = NULL;
	cub3d->map = init_map();
	cub3d->player = init_player();
	cub3d->raycast = init_raycasting();
	cub3d->image = init_image();
}
