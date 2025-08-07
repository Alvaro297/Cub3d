/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-07 18:53:49 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-07 18:53:49 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_raycasting	init_raycasting(void)
{
	t_raycasting	rc;

	rc.delta_dist_x = 0.0;
	rc.delta_dist_y = 0.0;
	rc.raydir_x = 0.0;
	rc.raydir_y = 0.0;
	rc.side_dist_x = 0.0;
	rc.side_dist_y = 0.0;
	rc.step_x = 0;
	rc.step_y = 0;
	rc.is_horizontal = false;
	rc.perp_wall_dist = 0.0;
	rc.wall_hit_x = 0.0;
	rc.wall_hit_y = 0.0;
	rc.hit_type = '\0';
	return (rc);
}

static t_texture	init_texture(void)
{
	t_texture	tex;

	tex.img_ptr = NULL;
	tex.data = NULL;
	tex.width = 0;
	tex.height = 0;
	tex.bits_per_pixel = 0;
	tex.line_length = 0;
	tex.endian = 0;
	return (tex);
}

t_image	init_image(void)
{
	t_image	image;

	image.img_ptr = NULL;
	image.data = NULL;
	image.bits_per_pixel = 0;
	image.line_length = 0;
	image.endian = 0;
	image.animation_frame = 0;
	image.animation_frame_west = 0;
	image.tex_north = init_texture();
	image.tex_south = init_texture();
	image.tex_east = init_texture();
	image.tex_west = init_texture();
	return (image);
}
