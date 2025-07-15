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

void	wall_hit(t_cub3d *cub3d, bool is_horizontal, int map)
{
	cub3d->raycast.is_horizontal = is_horizontal;
	if (is_horizontal)
	{
		cub3d->raycast.perp_wall_dist =
			(map - cub3d->player.x_position
				+ (1 - cub3d->raycast.step_x) / 2) / cub3d->raycast.raydir_x;
		cub3d->raycast.wall_hit_x = cub3d->player.x_position
			+ cub3d->raycast.perp_wall_dist * cub3d->raycast.raydir_x;
		cub3d->raycast.wall_hit_y = map;
	}
	else
	{
		cub3d->raycast.perp_wall_dist =
			(map - cub3d->player.y_position
				+ (1 - cub3d->raycast.step_y) / 2) / cub3d->raycast.raydir_y;
		cub3d->raycast.wall_hit_y = cub3d->player.y_position
			+ cub3d->raycast.perp_wall_dist * cub3d->raycast.raydir_y;
		cub3d->raycast.wall_hit_x = map;
	}
}

void	dda_loop(t_cub3d *cub3d, int map_x, int map_y)
{
	while (1)
	{
		if (cub3d->raycast.sideDist_x < cub3d->raycast.sideDist_y)
		{
			cub3d->raycast.sideDist_x += cub3d->raycast.delta_dist_x;
			map_x += (int) cub3d->raycast.step_x;
			if (map_x < 0 || map_y < 0 || !cub3d->map.matriz)
				break;
			int num_rows = 0;
			while (cub3d->map.matriz[num_rows])
				num_rows++;
			
			if (map_y >= num_rows || !cub3d->map.matriz[map_y] || 
				map_x >= (int)strlen(cub3d->map.matriz[map_y]))
				break;
			
			if (cub3d->map.matriz[map_y][map_x] == '1'
					|| cub3d->map.matriz[map_y][map_x] == '2')
			{
				wall_hit(cub3d, true, map_x);
				cub3d->raycast.hit_type = cub3d->map.matriz[map_y][map_x];
				break;
			}
		}
		else
		{
			cub3d->raycast.sideDist_y += cub3d->raycast.delta_dist_y;
			map_y += (int) cub3d->raycast.step_y;
			if (map_x < 0 || map_y < 0 || !cub3d->map.matriz)
				break;
			int num_rows = 0;
			while (cub3d->map.matriz[num_rows])
				num_rows++;
			if (map_y >= num_rows || !cub3d->map.matriz[map_y] || 
				map_x >= (int)strlen(cub3d->map.matriz[map_y]))
				break;
			if (cub3d->map.matriz[map_y][map_x] == '1'
					|| cub3d->map.matriz[map_y][map_x] == '2')
			{
				wall_hit(cub3d, false, map_y);
				cub3d->raycast.hit_type = cub3d->map.matriz[map_y][map_x];
				break;
			}
		}
	}
}
