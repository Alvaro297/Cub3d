/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-07 18:45:55 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-07 18:45:55 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	load_texture(t_cub3d *cub3d, t_texture *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(cub3d->mlx_ptr, path,
			&tex->width, &tex->height);
	if (tex->img_ptr)
		tex->data = mlx_get_data_addr(tex->img_ptr, &tex->bits_per_pixel,
				&tex->line_length, &tex->endian);
}

void	load_images(t_cub3d *cub3d)
{
	load_texture(cub3d, &cub3d->image.tex_north, cub3d->map.tex_no);
	load_texture(cub3d, &cub3d->image.tex_south, cub3d->map.tex_so);
	load_texture(cub3d, &cub3d->image.tex_east, cub3d->map.tex_ea);
	load_texture(cub3d, &cub3d->image.tex_west, cub3d->map.tex_we);
}
