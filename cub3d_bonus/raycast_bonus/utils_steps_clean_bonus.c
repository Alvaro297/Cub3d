/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_steps_clean_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 23:10:39 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-10 23:10:39 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	step_direccion(t_cub3d *cub3d, int map_x, int map_y)
{
	if (cub3d->raycast.raydir_x < 0)
	{
		cub3d->raycast.step_x = -1;
		cub3d->raycast.side_dist_x = (cub3d->player.x_position - map_x)
			* cub3d->raycast.delta_dist_x;
	}
	else
	{
		cub3d->raycast.step_x = 1;
		cub3d->raycast.side_dist_x = (map_x + 1.0 - cub3d->player.x_position)
			* cub3d->raycast.delta_dist_x;
	}
	if (cub3d->raycast.raydir_y < 0)
	{
		cub3d->raycast.step_y = -1;
		cub3d->raycast.side_dist_y = (cub3d->player.y_position - map_y)
			* cub3d->raycast.delta_dist_y;
	}
	else
	{
		cub3d->raycast.step_y = 1;
		cub3d->raycast.side_dist_y = (map_y + 1.0 - cub3d->player.y_position)
			* cub3d->raycast.delta_dist_y;
	}
}

void	wall_hit(t_cub3d *cub3d, int side, int map_x, int map_y)
{
	if (side == 0)
	{
		cub3d->raycast.perp_wall_dist = (map_x - cub3d->player.x_position + (1
					- cub3d->raycast.step_x) / 2) / cub3d->raycast.raydir_x;
		cub3d->raycast.wall_hit_y = cub3d->player.y_position
			+ cub3d->raycast.perp_wall_dist * cub3d->raycast.raydir_y;
		cub3d->raycast.wall_hit_x = map_x;
		if (cub3d->raycast.step_x == -1)
			cub3d->raycast.wall_hit_x += 1.0;
	}
	else
	{
		cub3d->raycast.perp_wall_dist = (map_y - cub3d->player.y_position + (1
					- cub3d->raycast.step_y) / 2) / cub3d->raycast.raydir_y;
		cub3d->raycast.wall_hit_x = cub3d->player.x_position
			+ cub3d->raycast.perp_wall_dist * cub3d->raycast.raydir_x;
		cub3d->raycast.wall_hit_y = map_y;
		if (cub3d->raycast.step_y == -1)
			cub3d->raycast.wall_hit_y += 1.0;
	}
	if (cub3d->raycast.perp_wall_dist < 0.01)
		cub3d->raycast.perp_wall_dist = 0.01;
}
