#include "cub3d.h"

static t_minimap	init_minimap(t_cub3d *cub3d)
{
	t_minimap	m;

	m.map_rows = cub3d->map.height;
	m.map_cols = cub3d->map.width;
	m.max_width = SCREEN_WIDTH * 0.2;
	m.max_height = SCREEN_HEIGHT * 0.2;
	m.scale_x = m.max_width / m.map_cols;
	m.scale_y = m.max_height / m.map_rows;
	if (m.scale_x < m.scale_y)
		cub3d->map.map_scale = m.scale_x;
	else
		cub3d->map.map_scale = m.scale_y;
	if (cub3d->map.map_scale < 1)
		cub3d->map.map_scale = 1;
	return (m);
}

static void	put_pixel_map(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


static void	print_map(t_image *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel_map(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_cub3d *cub3d)
{
	t_minimap	*m;
	int			i;
	int			j;
	int			screen_x;
	int			screen_y;
	int			player_x;
	int			player_y;
	int			cell_size;

	cub3d->minimap = init_minimap(cub3d);
	m = &cub3d->minimap;

	i = 0;
	cell_size = cub3d->map.map_scale;
	while (i < m->map_rows)
	{
		j = 0;
		while (j < m->map_cols)
		{
			screen_x = 10 + j * cell_size;
			screen_y = 10 + i * cell_size;
			if (cub3d->map.matriz[i][j] == '1')
				print_map(&cub3d->image, screen_x, screen_y, cell_size, 0xFFFFFF);
			else
				print_map(&cub3d->image, screen_x, screen_y, cell_size, 0x000000);
			j++;
		}
		i++;
	}
	player_x = 10 + cub3d->player.x_position * cell_size;
	player_y = 10 + cub3d->player.y_position * cell_size;
	print_map(&cub3d->image, player_x - 1, player_y - 1, 3, 0xFF0000);
}
