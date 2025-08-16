/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 21:40:03 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-10 21:40:03 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static bool	close_door(t_player *player, t_door *door)
{
	double	dx;
	double	dy;
	double	distance;

	dx = player->x_position - (door->x + 0.5);
	dy = player->y_position - (door->y + 0.5);
	distance = sqrt(dx * dx + dy * dy);
	return (distance > 1.2);
}

void	update_doors(t_cub3d *cub3d)
{
	int		i;
	t_door	*door;

	i = 0;
	while (i < cub3d->map.n_doors)
	{
		door = &cub3d->map.door[i];
		if (door->is_open && door->animation < 1.0)
			door->animation += 0.05;
		else if (!door->is_open && door->animation > 0.0)
			door->animation -= 0.05;
		if (door->is_open && close_door(&cub3d->player, door))
		{
			door->is_open = false;
			door->animation = 1.0;
		}
		i++;
	}
}

static double	door_distance(t_player *player, t_door *door)
{
	double	dx;
	double	dy;

	dy = player->y_position - door->y;
	dx = player->x_position - door->x;
	return (dx * dx + dy * dy);
}

void	toogle_door(t_cub3d *cub3d)
{
	int		i;
	t_door	*door;

	i = 0;
	while (i < cub3d->map.n_doors)
	{
		door = &cub3d->map.door[i];
		if (door_distance(&cub3d->player, door) < (1.5 * 1.5))
		{
			door->is_open = !door->is_open;
			if (door->is_open)
				door->animation = 1.0;
			else
				door->animation = 0.0;
			break ;
		}
		i++;
	}
}
