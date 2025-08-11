/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_clean_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 23:10:56 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-10 23:10:56 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (cub3d->raycast.side_dist_x < cub3d->raycast.side_dist_y)
	{
		cub3d->raycast.side_dist_x += cub3d->raycast.delta_dist_x;
		*map_x += cub3d->raycast.step_x;
		*side = 0;
	}
	else
	{
		cub3d->raycast.side_dist_y += cub3d->raycast.delta_dist_y;
		*map_y += cub3d->raycast.step_y;
		*side = 1;
	}
}

static bool	dda_finish(t_cub3d *cub3d, int map_x, int map_y, int side)
{
	char	cell;

	cell = '\0';
	if (map_y < 0 || map_y >= cub3d->map.height
		|| map_x < 0 || map_x >= cub3d->map.width)
	{
		hited_wall(cub3d, side, map_x, map_y);
		return (true);
	}
	cell = cub3d->map.matriz[map_y][map_x];
	if (cell == '1')
	{
		hited_wall(cub3d, side, map_x, map_y);
		return (true);
	}
	else if (cell == '2' && hit_door(cub3d, side, map_x, map_y))
		return (true);
	if (cub3d->raycast.side_dist_x > 20.0
		&& cub3d->raycast.side_dist_y > 20.0)
		return (true);
	return (false);
}

void	dda_loop(t_cub3d *cub3d, int map_x, int map_y)
{
	int		side;
	int		max_iterations;

	max_iterations = 64;
	while (max_iterations-- > 0)
	{
		dda_loop_help(cub3d, &map_x, &map_y, &side);
		if (dda_finish(cub3d, map_x, map_y, side))
			break ;
	}
}
