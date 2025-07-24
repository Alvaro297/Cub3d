#include "../cub3d_bonus.h"


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
	t_movement move;

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

	player.img = NULL;
	player.x_position = 0;
	player.player_count = 0;
	player.y_position = 0;
	player.movement = init_movement();
	return (player);
}

t_raycasting	init_raycasting(void)
{
	t_raycasting rc;

	rc.delta_dist_x = 0.0;
	rc.delta_dist_y = 0.0;
	rc.raydir_x = 0.0;
	rc.raydir_y = 0.0;
	rc.sideDist_x = 0.0;
	rc.sideDist_y = 0.0;
	rc.step_x = 0;
	rc.step_y = 0;
	rc.is_horizontal = false;
	rc.perp_wall_dist = 0.0;
	rc.wall_hit_x = 0.0;
	rc.wall_hit_y = 0.0;
	rc.hit_type = '\0';
	return (rc);
}

t_minimap	init_minimap(t_cub3d *cub3d)
{
	t_minimap	m;

	m.map_rows = cub3d->map.height;
	m.map_cols = cub3d->map.width;
	m.max_width = SCREEN_WIDTH * 0.5;
	m.max_height = SCREEN_HEIGHT * 0.5;
	m.scale_x = m.max_width / m.map_cols;
	m.scale_y = m.max_height / m.map_rows;
	if (m.scale_x < m.scale_y)
		cub3d->map.map_scale = m.scale_x;
	else
		cub3d->map.map_scale = m.scale_y;
	if (cub3d->map.map_scale < 1)
		cub3d->map.map_scale = 1;
	return (m);
}

void	init_cub3d(t_cub3d *cub3d)
{
	/* cub3d->mlx_ptr = mlx_init();
	cub3d->win_ptr = mlx_new_window(cub3d->mlx_ptr, 1280, 720, "Cub3d");
	cub3d->img_ptr = mlx_new_image(cub3d->mlx_ptr, 1280, 720); */
	cub3d->map = init_map();
	cub3d->player = init_player();
	cub3d->raycast = init_raycasting();
	
	
}
