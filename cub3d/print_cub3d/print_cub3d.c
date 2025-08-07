/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-07 16:52:54 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-07 16:52:54 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clear_buffer(t_cub3d *cub3d, int color)
{
	int	*buffer;
	int	total_pixels;
	int	i;

	buffer = (int *)cub3d->image.data;
	total_pixels = SCREEN_WIDTH * SCREEN_HEIGHT;
	i = 0;
	while (i < total_pixels)
	{
		buffer[i] = color;
		i++;
	}
}

static unsigned int	put_all_help(t_cub3d *cub3d,
		int draw_start, int draw_end, t_help help)
{
	unsigned int	wall_color;

	if (!cub3d->raycast.is_horizontal)
	{
		if (cub3d->raycast.raydir_x < 0)
			help.direction = 2;
		else
			help.direction = 3;
	}
	else
	{
		if (cub3d->raycast.raydir_y < 0)
			help.direction = 0;
		else
			help.direction = 1;
	}
	wall_color = print_textures(cub3d, help, draw_start, draw_end);
	return (wall_color);
}

void	put_all(t_cub3d *cub3d, int draw_start, int draw_end, int x)
{
	unsigned int	wall_color;
	t_help			help;

	help.y = draw_start;
	while (help.y < draw_end)
	{
		wall_color = put_all_help(cub3d, draw_start, draw_end, help);
		if (help.y >= 0 && help.y < SCREEN_HEIGHT)
			put_pixel_to_buffer(cub3d, x, help.y, (int)wall_color);
		help.y++;
	}
}

void	print_cub3d(t_cub3d *cub3d, int x)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	dist;

	dist = cub3d->raycast.perp_wall_dist;
	line_height = (int)(SCREEN_HEIGHT / dist);
	if (line_height > SCREEN_HEIGHT * 10)
		line_height = SCREEN_HEIGHT * 10;
	if (line_height < 1)
		line_height = 1;
	draw_start = (SCREEN_HEIGHT - line_height) / 2;
	draw_end = draw_start + line_height;
	put_all(cub3d, draw_start, draw_end, x);
}
