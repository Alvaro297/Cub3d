# include "../cub3d.h"

void	step_direccion(t_cub3d *cub3d, int x, int map_x, int map_y)
{
	if (cub3d->raycast.raydir_x[x] < 0)
	{
		cub3d->raycast.step_x[x] = -1;
		cub3d->raycast.sideDist_x[x] = (cub3d->player.x_position - map_x)
		* cub3d->raycast.delta_dist_x[x];
	}
	else
	{
		cub3d->raycast.step_x[x] = 1;
		cub3d->raycast.sideDist_x[x] = (map_x + 1.0 - cub3d->player.x_position)
		* cub3d->raycast.delta_dist_x[x];
	}
	if (cub3d->raycast.raydir_y[x] < 0)
	{
		cub3d->raycast.step_y[x] = -1;
		cub3d->raycast.sideDist_y[x] = (cub3d->player.y_position - map_y)
		* cub3d->raycast.delta_dist_y[x];
	}
	else
	{
		cub3d->raycast.step_y[x] = 1;
		cub3d->raycast.sideDist_y[x] = (map_y + 1.0 - cub3d->player.y_position)
			* cub3d->raycast.delta_dist_y[x];
	}
}

void	wall_hit(t_cub3d *cub3d, int x, bool is_horizontal, int map)
{
	cub3d->raycast.is_horizontal[x] = is_horizontal;
	if (is_horizontal)
	{
		cub3d->raycast.perp_wall_dist[x] =
			(map - cub3d->player.x_position
				+ (1 - cub3d->raycast.step_x[x]) / 2) / cub3d->raycast.raydir_x[x];
		cub3d->raycast.wall_hit_x[x] = cub3d->player.x_position
			+ cub3d->raycast.perp_wall_dist[x] * cub3d->raycast.raydir_x[x];
		cub3d->raycast.wall_hit_y[x] = map;
	}

	else
	{
		cub3d->raycast.perp_wall_dist[x] =
			(map - cub3d->player.y_position
				+ (1 - cub3d->raycast.step_y[x]) / 2) / cub3d->raycast.raydir_y[x];
		cub3d->raycast.wall_hit_y[x] = cub3d->player.y_position
			+ cub3d->raycast.perp_wall_dist[x] * cub3d->raycast.raydir_y[x];
		cub3d->raycast.wall_hit_x[x] = map;
	}
}

void	dda_loop(t_cub3d *cub3d, int x, int map_x, int map_y)
{
	bool	is_wall;

	while (1)
	{
		if (cub3d->raycast.sideDist_x[x] > cub3d->raycast.sideDist_y[x])
		{
			cub3d->raycast.sideDist_x[x] += cub3d->raycast.delta_dist_x[x];
			map_x += (int) cub3d->raycast.step_x[x];
			if (cub3d->map.matriz[map_x][map_y] == '1'
					|| cub3d->map.matriz[map_x][map_y] == '2')
			{
				wall_hit(cub3d, x, true, map_x);
				cub3d->raycast.hit_type = cub3d->map.matriz[map_x][map_y];
				break;
			}
			
		}
		else
		{
			cub3d->raycast.sideDist_y[x] += cub3d->raycast.delta_dist_y[x];
			map_y += (int) cub3d->raycast.step_y[x];
			if (cub3d->map.matriz[map_x][map_y] == '1'
					|| cub3d->map.matriz[map_x][map_y] == '2')
			{
				wall_hit(cub3d, x, false, map_y);
				break;
			}
		}
	}
}

void	steps(t_cub3d *cub3d)
{
	int	x;
	int	map_x;
	int	map_y;

	map_x = (int)cub3d->player.x_position;
	map_y = (int)cub3d->player.y_position;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		step_direccion(cub3d, x, map_x, map_y);
		dda_loop(cub3d, x, map_x, map_y);
		x++;
	}
}
