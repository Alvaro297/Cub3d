/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 23:16:11 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-10 23:16:11 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static bool	update_animation_frames(t_cub3d *cub3d)
{
	static int	frame_x = 0;
	static int	frame_y = 5;
	bool		re_casting;

	re_casting = false;
	frame_x++;
	frame_y++;
	if (frame_x % 10 == 0)
	{
		re_casting = true;
		cub3d->image.animation_frame++;
		if (cub3d->image.animation_frame >= TOTAL_ANIMATIONS)
			cub3d->image.animation_frame = 0;
	}
	if (frame_y % 10 == 0)
	{
		re_casting = true;
		cub3d->image.animation_frame_west++;
		if (cub3d->image.animation_frame_west >= TOTAL_ANIMATIONS)
			cub3d->image.animation_frame_west = 0;
	}
	return (re_casting);
}

void	ft_animation(t_cub3d *cub3d)
{
	if (update_animation_frames(cub3d))
	{
		raycast(cub3d);
		draw_minimap(cub3d);
	}
}
