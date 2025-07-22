#include "cub3d.h"

/* static void	print_minimap(t_minimap *m)
{
	printf("=== MINIMAP ===\n");
	printf("map_rows:    %d\n", m->map_rows);
	printf("map_cols:    %d\n", m->map_cols);
	printf("max_width:   %d\n", m->max_width);
	printf("max_height:  %d\n", m->max_height);
	printf("scale_x:     %d\n", m->scale_x);
	printf("scale_y:     %d\n", m->scale_y);
	printf("================\n");
} */

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
	int			i;
	int			j;
	int			screen_x;
	int			screen_y;
	int			player_x;
	int			player_y;
	
	int			cell_size;
	cub3d->minimap = init_minimap(cub3d);
	cell_size = 0;
	i = 0;
	cell_size = cub3d->map.map_scale;
	while (i < cub3d->minimap.map_rows)
	{
		j = 0;
		while (j < cub3d->minimap.map_cols)
		{
			screen_x = 10 + j * cell_size;
			screen_y = 10 + i * cell_size;
			char c = cub3d->map.matriz_norm[i][j];
			if (c == '1')
				print_map(&cub3d->image, screen_x, screen_y, cell_size, 0xFFFFFF);
			else if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
				print_map(&cub3d->image, screen_x, screen_y, cell_size, 0x000000);
			else
				print_map(&cub3d->image, screen_x, screen_y, cell_size, 0x444444);
			j++;
		}
		i++;
	}
	player_x = 10 + cub3d->player.x_position * cell_size;
	player_y = 10 + cub3d->player.y_position * cell_size;
	print_map(&cub3d->image, player_x - 1, player_y - 1, 3, 0xFF0000);
	render_buffer_to_window(cub3d);
}
