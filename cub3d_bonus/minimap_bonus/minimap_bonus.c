/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 21:41:37 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-10 21:41:37 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	put_pixel_map(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	print_map(t_cub3d *cub3d, int size, int color, bool is_player)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (is_player)
				put_pixel_map(&cub3d->image, cub3d->minimap.player_x + j,
					cub3d->minimap.player_y + i, color);
			else
				put_pixel_map(&cub3d->image, cub3d->minimap.screen_x + j,
					cub3d->minimap.screen_y + i, color);
			j++;
		}
		i++;
	}
}

static void	draw_minimap_help(t_cub3d *cub3d, int i, int cell_size)
{
	int		j;
	char	c;

	c = '\0';
	j = 0;
	while (j < cub3d->minimap.map_cols)
	{
		cub3d->minimap.screen_x = 10 + j * cell_size;
		cub3d->minimap.screen_y = 10 + i * cell_size;
		c = cub3d->map.matriz_norm[i][j];
		if (c == '1')
			print_map(cub3d, cell_size, 0xFFFFFF, false);
		else if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			print_map(cub3d, cell_size, 0x000000, false);
		else if (c == '2')
		{
			if (get_door(cub3d, i, j))
				print_map(cub3d, cell_size, 0x00FF00, false);
			else
				print_map(cub3d, cell_size, MORAO, false);
		}
		else
			print_map(cub3d, cell_size, 0x444444, false);
		j++;
	}
}

void	draw_minimap(t_cub3d *cub3d)
{
	int			i;
	int			cell_size;

	cub3d->minimap = init_minimap(cub3d);
	cell_size = cub3d->map.map_scale;
	i = 0;
	while (i < cub3d->minimap.map_rows)
	{
		draw_minimap_help(cub3d, i, cell_size);
		i++;
	}
	cub3d->minimap.player_x = 10 + cub3d->player.x_position * cell_size;
	cub3d->minimap.player_y = 10 + cub3d->player.y_position * cell_size;
	print_map(cub3d, 3, 0xFF0000, true);
	render_buffer_to_window(cub3d);
}
