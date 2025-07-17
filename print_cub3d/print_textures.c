# include "../cub3d.h"

int	print_north(t_cub3d *cub3d, int direction, int y, int draw_end)
{
	double	wall_x;
	double	dec_x;

	if (cub3d->raycast.is_horizontal)
		wall_x = cub3d->raycast.wall_hit_x;
	else
		wall_x = cub3d->raycast.wall_hit_y;
	dec_x = wall_x - floor(wall_x);
	
}

int	print_textures(t_cub3d *cub3d, int direction, int y, int draw_end)
{	
	if (direction == 0)
		return (print_north(cub3d, direction, y, draw_end));
	else if (direction == 1)
		return (print_south(cub3d, direction, y, draw_end));
	else if (direction == 2)
		return (print_west(cub3d, direction, y, draw_end));
	else if (direction == 3)
		return (print_east(cub3d, direction, y, draw_end));
	else
		return (printf("Error en el tipo"), 1);
}