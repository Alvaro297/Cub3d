# include "../cub3d.h"

void	step_direccion(t_cub3d *cub3d, int map_x, int map_y)
{
	if (cub3d->raycast.raydir_x < 0)
	{
		cub3d->raycast.step_x = -1;
		cub3d->raycast.sideDist_x = (cub3d->player.x_position - map_x)
			* cub3d->raycast.delta_dist_x;
	}
	else
	{
		cub3d->raycast.step_x = 1;
		cub3d->raycast.sideDist_x = (map_x + 1.0 - cub3d->player.x_position)
			* cub3d->raycast.delta_dist_x;
	}
	if (cub3d->raycast.raydir_y < 0)
	{
		cub3d->raycast.step_y = -1;
		cub3d->raycast.sideDist_y = (cub3d->player.y_position - map_y)
			* cub3d->raycast.delta_dist_y;
	}
	else
	{
		cub3d->raycast.step_y = 1;
		cub3d->raycast.sideDist_y = (map_y + 1.0 - cub3d->player.y_position)
			* cub3d->raycast.delta_dist_y;
	}
}

void	wall_hit(t_cub3d *cub3d, int side, int map_x, int map_y)
{
	if (side == 0)
	{
		cub3d->raycast.perp_wall_dist = (map_x - cub3d->player.x_position + (1 - cub3d->raycast.step_x) / 2) / cub3d->raycast.raydir_x;
		cub3d->raycast.wall_hit_y = cub3d->player.y_position + cub3d->raycast.perp_wall_dist * cub3d->raycast.raydir_y;
		cub3d->raycast.wall_hit_x = map_x;
		if (cub3d->raycast.step_x == -1)
			cub3d->raycast.wall_hit_x += 1.0;
	}
	else
	{
		cub3d->raycast.perp_wall_dist = (map_y - cub3d->player.y_position + (1 - cub3d->raycast.step_y) / 2) / cub3d->raycast.raydir_y;
		cub3d->raycast.wall_hit_x = cub3d->player.x_position + cub3d->raycast.perp_wall_dist * cub3d->raycast.raydir_x;
		cub3d->raycast.wall_hit_y = map_y;
		if (cub3d->raycast.step_y == -1)
			cub3d->raycast.wall_hit_y += 1.0;
	}
	if (cub3d->raycast.perp_wall_dist < 0.01)
		cub3d->raycast.perp_wall_dist = 0.01;
}

static void hited_wall(t_cub3d *cub3d, int side, int map_x, int map_y)
{

	if (side == 0)
		cub3d->raycast.is_horizontal = false;
	else
		cub3d->raycast.is_horizontal = true;
	wall_hit(cub3d, side, map_x, map_y);
	cub3d->raycast.hit_type = cub3d->map.matriz[map_y][map_x];
}
static void dda_loop_help(t_cub3d *cub3d, int *map_x, int *map_y, int *side)
{
	if (cub3d->raycast.sideDist_x < cub3d->raycast.sideDist_y)
	{
		cub3d->raycast.sideDist_x += cub3d->raycast.delta_dist_x;
		*map_x += cub3d->raycast.step_x;
		*side = 0;
	}
	else
	{
		cub3d->raycast.sideDist_y += cub3d->raycast.delta_dist_y;
		*map_y += cub3d->raycast.step_y;
		*side = 1;
	}
}

void	dda_loop(t_cub3d *cub3d, int map_x, int map_y)
{
	int		side;

	while (1)
	{
		dda_loop_help(cub3d, &map_x, &map_y, &side);
		if (map_y < 0 || map_y >= cub3d->map.height ||
				map_x < 0 || map_x >= cub3d->map.width)
			break;
		if (cub3d->map.matriz[map_y][map_x] == '1')
		{
			hited_wall(cub3d, side, map_x, map_y);
			break;
		}
	}
}