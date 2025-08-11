/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cub3d_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 23:08:12 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-10 23:08:12 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	clear_buffer(t_cub3d *cub3d, int color)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			put_pixel_to_buffer(cub3d, x, y, color);
			x++;
		}
		y++;
	}
}

static unsigned int	put_all_help(t_cub3d *cub3d,
		int draw_start, int draw_end, t_help help)
{
	unsigned int	wall_color;

	if (cub3d->raycast.hit_type == '2')
		help.direction = 4;
	else if (!cub3d->raycast.is_horizontal)
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

static void	put_all(t_cub3d *cub3d, int draw_start, int draw_end, int x)
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
