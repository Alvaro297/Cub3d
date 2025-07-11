# include "../cub3d.h"

void	put_all(t_cub3d *cub3d, int draw_start, int draw_end, int x)
{
	int	y;

	y = 0;
	while (y < draw_start)
		mlx_pixel_put(cub3d->mlx_ptr, cub3d->win_ptr, x, y++, GREY);
	while (draw_start < draw_end)
	{
		if (cub3d->raycast.is_horizontal)
		{
			if ((int) cub3d->raycast.raydir_y < 0)
				mlx_pixel_put(cub3d->mlx_ptr, cub3d->win_ptr, x, draw_start++, RED);
			else
				mlx_pixel_put(cub3d->mlx_ptr, cub3d->win_ptr, x, draw_start++, BLUE);
		}
		else
		{
			if ((int) cub3d->raycast.raydir_x < 0)
				mlx_pixel_put(cub3d->mlx_ptr, cub3d->win_ptr, x, draw_start++, GREEN);
			else
				mlx_pixel_put(cub3d->mlx_ptr, cub3d->win_ptr, x, draw_start++, YELLOW);
		}
	}
	while (draw_end < SCREEN_HEIGHT)
		mlx_pixel_put(cub3d->mlx_ptr, cub3d->win_ptr, x, draw_end++, BLACK);
}

void	 print_cub3d(t_cub3d *cub3d, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	
	line_height = SCREEN_WIDTH / cub3d->raycast.perp_wall_dist;
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
