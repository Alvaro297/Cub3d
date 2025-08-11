/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 22:37:32 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-10 22:37:32 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	load_images_animated_help(t_cub3d *cub3d, int i, char *path)
{
	cub3d->image.tex_west[i].img_ptr
		= mlx_xpm_file_to_image(cub3d->mlx_ptr, path,
			&cub3d->image.tex_west[i].width, &cub3d->image.tex_west[i].height);
	if (cub3d->image.tex_west[i].img_ptr)
		cub3d->image.tex_west[i].data
			= mlx_get_data_addr(cub3d->image.tex_west[i].img_ptr,
				&cub3d->image.tex_west[i].bits_per_pixel,
				&cub3d->image.tex_west[i].line_length,
				&cub3d->image.tex_west[i].endian);
}

static void	load_images_animated_east(t_cub3d *cub3d, int i)
{
	char	*path;
	char	*num;
	char	*name_path;

	num = ft_itoa(i);
	name_path = ft_strjoin("textures/animation/animation_east_", num);
	path = ft_strjoin_free(name_path, ".xpm");
	free(num);
	cub3d->image.tex_east[i].img_ptr
		= mlx_xpm_file_to_image(cub3d->mlx_ptr, path,
			&cub3d->image.tex_east[i].width,
			&cub3d->image.tex_east[i].height);
	if (cub3d->image.tex_east[i].img_ptr)
		cub3d->image.tex_east[i].data
			= mlx_get_data_addr(cub3d->image.tex_east[i].img_ptr,
				&cub3d->image.tex_east[i].bits_per_pixel,
				&cub3d->image.tex_east[i].line_length,
				&cub3d->image.tex_east[i].endian);
	free(path);
}

static void	load_images_animated(t_cub3d *cub3d)
{
	int		i;
	char	*path;
	char	*num;
	char	*name_path;

	i = 1;
	while (i < TOTAL_ANIMATIONS)
	{
		load_images_animated_east(cub3d, i);
		num = ft_itoa(i);
		name_path = ft_strjoin("textures/animation/animation_west_", num);
		path = ft_strjoin_free(name_path, ".xpm");
		free(num);
		load_images_animated_help(cub3d, i, path);
		free(path);
		i++;
	}
}

static void	load_images_door(t_cub3d *cub3d)
{
	cub3d->image.doors.img_ptr = mlx_xpm_file_to_image(cub3d->mlx_ptr,
			"textures/door/door.xpm", &cub3d->image.doors.width,
			&cub3d->image.doors.height);
	if (cub3d->image.doors.img_ptr)
		cub3d->image.doors.data = mlx_get_data_addr(cub3d->image.doors.img_ptr,
				&cub3d->image.doors.bits_per_pixel,
				&cub3d->image.doors.line_length,
				&cub3d->image.doors.endian);
}

void	load_images(t_cub3d *cub3d)
{
	load_images_north_south(cub3d);
	load_images_east_west(cub3d);
	load_images_animated(cub3d);
	load_images_door(cub3d);
}
