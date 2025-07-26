#include "../cub3d_bonus.h"


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
		cub3d->raycast.perp_wall_dist = (map - cub3d->player.x_position + (1
					- cub3d->raycast.step_x) / 2) / cub3d->raycast.raydir_x;
		cub3d->raycast.wall_hit_x = cub3d->player.x_position
			+ cub3d->raycast.perp_wall_dist * cub3d->raycast.raydir_x;
		cub3d->raycast.wall_hit_y = map;
	}
	else
	{
		cub3d->raycast.perp_wall_dist = (map - cub3d->player.y_position + (1
					- cub3d->raycast.step_y) / 2) / cub3d->raycast.raydir_y;
		cub3d->raycast.wall_hit_y = cub3d->player.y_position
			+ cub3d->raycast.perp_wall_dist * cub3d->raycast.raydir_y;
		cub3d->raycast.wall_hit_x = map;
	}
}

void	dda_loop(t_cub3d *cub3d, int map_x, int map_y)
{
	char **map;

	map = cub3d->map.matriz_norm; // 🔄 usa mapa normalizado
	while (true)
	{
		if (cub3d->raycast.sideDist_x < cub3d->raycast.sideDist_y)
		{
			cub3d->raycast.sideDist_x += cub3d->raycast.delta_dist_x;
			map_x += cub3d->raycast.step_x;
			cub3d->raycast.is_horizontal = 0;
		}
		else
		{
			cub3d->raycast.sideDist_y += cub3d->raycast.delta_dist_y;
			map_y += cub3d->raycast.step_y;
			cub3d->raycast.is_horizontal = 1;
		}
		if (map_y < 0 || map_x < 0)
			break ;
		if (!map || !map[map_y])
			break ;
		if (map_x >= (int)ft_strlen(map[map_y]))
			break ;
		char c = map[map_y][map_x];
		if (c == '1')
		{
			cub3d->raycast.hit_type = c;
			if (cub3d->raycast.is_horizontal == 0)
				wall_hit(cub3d, true, map_x);
			else
				wall_hit(cub3d, false, map_y);
			break ;
		}
		else if (c == '2')
		{
			t_door *door = get_door(cub3d, map_x, map_y);
			if (!door || door->animation < 0.99) // 🔒 aún no abierta del todo
			{
				cub3d->raycast.hit_type = c;
				if (cub3d->raycast.is_horizontal == 0)
					wall_hit(cub3d, true, map_x);
				else
					wall_hit(cub3d, false, map_y);
				break ;
			}
		}
	}
}
