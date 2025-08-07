#include "../cub3d_bonus.h"

static bool	hit_door(t_cub3d *cub3d, int side, int map_x, int map_y)
{
	t_door	*door;

	door = get_door(cub3d, map_x, map_y);
	if (!door || door->animation < 0.99)
	{
		hited_wall(cub3d, side, map_x, map_y);
		return (true);
	}
	return (false);
}

void	hited_wall(t_cub3d *cub3d, int side, int map_x, int map_y)
{
	if (side == 0)
		cub3d->raycast.is_horizontal = false;
	else
		cub3d->raycast.is_horizontal = true;
	wall_hit(cub3d, side, map_x, map_y);
	cub3d->raycast.hit_type = cub3d->map.matriz[map_y][map_x];
}

void	dda_loop_help(t_cub3d *cub3d, int *map_x, int *map_y, int *side)
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
	char	cell;

	while (1)
	{
		dda_loop_help(cub3d, &map_x, &map_y, &side);
		if (map_y < 0 || map_y >= cub3d->map.height
			|| map_x < 0 || map_x >= cub3d->map.width)
			break;
		cell = cub3d->map.matriz[map_y][map_x];
		if (cell == '1')
		{
			hited_wall(cub3d, side, map_x, map_y);
			break ;
		}
		else if (cell == '2' && hit_door(cub3d, side, map_x, map_y))
			break ;
	}
}
