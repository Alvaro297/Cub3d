# include "../cub3d.h"

void	init_image_buffer(t_cub3d *cub3d)
{
	cub3d->image.img_ptr = mlx_new_image(cub3d->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	cub3d->image.data = mlx_get_data_addr(cub3d->image.img_ptr,
		&cub3d->image.bits_per_pixel,
		&cub3d->image.line_length,
		&cub3d->image.endian);
}

void	put_pixel_to_buffer(t_cub3d *cub3d, int x, int y, int color)
{
	int				pixel_index;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		pixel_index = y * cub3d->image.line_length + x * (cub3d->image.bits_per_pixel / 8);
		*(int *)(cub3d->image.data + pixel_index) = color;
	}
}

void	render_buffer_to_window(t_cub3d *cub3d)
{
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr, cub3d->image.img_ptr, 0, 0);
}

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

void	put_all(t_cub3d *cub3d, int draw_start, int draw_end, int x)
{
	int				y;
	unsigned int	wall_color;

	y = draw_start;
	while (y < draw_end)
	{
		if (cub3d->raycast.is_horizontal)
		{
			if (cub3d->raycast.raydir_y < 0)
				wall_color = print_textures(cub3d, 1, y, draw_start, draw_end); // Sur
			else
				wall_color = print_textures(cub3d, 0, y, draw_start, draw_end); // Norte
		}
		else
		{
			if (cub3d->raycast.raydir_x < 0)
				wall_color = print_textures(cub3d, 3, y, draw_start, draw_end); // Este
			else
				wall_color = print_textures(cub3d, 2, y, draw_start, draw_end); // Oeste
		}
		put_pixel_to_buffer(cub3d, x, y, (int)wall_color);
		y++;
	}
}

void	 print_cub3d(t_cub3d *cub3d, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	
	line_height = SCREEN_HEIGHT / cub3d->raycast.perp_wall_dist;
	draw_start = (SCREEN_HEIGHT / 2) - (line_height / 2);
	draw_end = (SCREEN_HEIGHT / 2) + (line_height / 2);
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end > SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;
	put_all(cub3d, draw_start, draw_end, x);
}
/*	int	i;

	printf("=== TEXTURAS ===\n");
	printf("NO: %s\n", cub3d->map.tex_no);
	printf("SO: %s\n", cub3d->map.tex_so);
	printf("WE: %s\n", cub3d->map.tex_we);
	printf("EA: %s\n", cub3d->map.tex_ea);
	printf("\n=== COLORES ===\n");
	printf("Suelo: %d,%d,%d\n",
		cub3d->map.rgb_floor[0],
		cub3d->map.rgb_floor[1],
		cub3d->map.rgb_floor[2]);
	printf("Techo: %d,%d,%d\n",
		cub3d->map.rgb_ceiling[0],
		cub3d->map.rgb_ceiling[1],
		cub3d->map.rgb_ceiling[2]);
	printf("\n=== MAPA ===\n");
	i = 0;
	while (cub3d->map.matriz[i])
	{
		printf("%s", cub3d->map.matriz[i]);
		i++;
	}
	printf("\n=== JUGADOR ===\n");
	printf("Posición X: %.1f\n", cub3d->player.x_position);
	printf("Posición Y: %.1f\n", cub3d->player.y_position);
	printf("Dirección: %c\n", cub3d->player.direction);
	printf("Ángulo: %.1f\n", cub3d->player.angle);
	printf("================\n");
}*/
