/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cub3d_help_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 22:58:03 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-10 22:58:03 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	init_image_buffer(t_cub3d *cub3d)
{
	cub3d->image.img_ptr = mlx_new_image(cub3d->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	cub3d->image.data = mlx_get_data_addr(cub3d->image.img_ptr,
			&cub3d->image.bits_per_pixel, &cub3d->image.line_length,
			&cub3d->image.endian);
}

void	put_pixel_to_buffer(t_cub3d *cub3d, int x, int y, int color)
{
	int	pixel_index;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		pixel_index = y * cub3d->image.line_length + x
			* (cub3d->image.bits_per_pixel / 8);
		*(int *)(cub3d->image.data + pixel_index) = color;
	}
}

void	render_buffer_to_window(t_cub3d *cub3d)
{
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr,
		cub3d->image.img_ptr, 0, 0);
}

void	render_ceiling_floor(t_cub3d *cub3d)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			put_pixel_to_buffer(cub3d, x, y, cub3d->map.ceiling);
			x++;
		}
		y++;
	}
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			put_pixel_to_buffer(cub3d, x, y, cub3d->map.floor);
			x++;
		}
		y++;
	}
}
