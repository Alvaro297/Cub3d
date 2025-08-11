/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 22:21:18 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-10 22:21:18 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	rotate_player(t_cub3d *cub3d, double rot)
{
	cub3d->player.angle += rot;
	if (cub3d->player.angle < 0)
		cub3d->player.angle += 2 * 3.14159265359;
	if (cub3d->player.angle >= 2 * 3.14159265359)
		cub3d->player.angle -= 2 * 3.14159265359;
	cub3d->player.direccion_x = cos(cub3d->player.angle);
	cub3d->player.direccion_y = sin(cub3d->player.angle);
}

int	ft_mouse_hook(int x, int y, t_cub3d *cub3d)
{
	static int	last_x = -1;
	static int	initialized = 0;
	static int	skip_frames = 0;
	double		rot;

	(void)y;
	if (!initialized)
	{
		last_x = x;
		initialized = 1;
		return (0);
	}
	skip_frames++;
	if (skip_frames < 8)
		return (0);
	skip_frames = 0;
	if (abs(x - last_x) > 2)
	{
		rot = (x - last_x) * 0.001;
		rotate_player(cub3d, rot);
		last_x = x;
	}
	return (0);
}
