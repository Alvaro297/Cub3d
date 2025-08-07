/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-07 17:47:42 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-07 17:47:42 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	calc_tex_y(t_texture *tex, int draw_end, int draw_start, int y)
{
	int		total;
	double	wall_pos;

	wall_pos = 0.0;
	if (draw_end != draw_start)
	{
		wall_pos = (double)(y - draw_start) / (double)(draw_end - draw_start);
		if (wall_pos < 0.0)
			wall_pos = 0.0;
		if (wall_pos > 1.0)
			wall_pos = 1.0;
		total = (int)(wall_pos * (double)tex->height);
	}
	else
		total = 0;
	return (total);
}

static void	print_texture_help(t_texture *tex, int *tex_x, int *tex_y)
{
	if (*tex_x < 0)
		*tex_x = 0;
	if (*tex_x >= tex->width)
		*tex_x = tex->width - 1;
	if (*tex_y < 0)
		*tex_y = 0;
	if (*tex_y >= tex->height)
		*tex_y = tex->height - 1;
}

unsigned int	print_textures(t_cub3d *cub3d, t_help help,
		int draw_start, int draw_end)
{
	double		wall_x;
	int			tex_x;
	int			tex_y;
	t_texture	*tex;

	if (help.direction == 0)
		tex = &cub3d->image.tex_north;
	else if (help.direction == 1)
		tex = &cub3d->image.tex_south;
	else if (help.direction == 2)
		tex = &cub3d->image.tex_west;
	else
		tex = &cub3d->image.tex_east;
	if (cub3d->raycast.is_horizontal)
		wall_x = cub3d->raycast.wall_hit_x;
	else
		wall_x = cub3d->raycast.wall_hit_y;
	wall_x = wall_x - floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if ((!cub3d->raycast.is_horizontal && cub3d->raycast.raydir_x > 0)
		|| (cub3d->raycast.is_horizontal && cub3d->raycast.raydir_y < 0))
		tex_x = tex->width - tex_x - 1;
	tex_y = calc_tex_y(tex, draw_end, draw_start, help.y);
	print_texture_help(tex, &tex_x, &tex_y);
	return (get_texture_color(tex, tex_x, tex_y));
}
