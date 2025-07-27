#include "../cub3d.h"

void	starting_raycasting(t_cub3d *cub3d, char pos_player)
{
	if (pos_player == 'N')
	{
		cub3d->player.direccion_y = 0;
		cub3d->player.direccion_x = -1;
	}
	else if (pos_player == 'E')
	{
		cub3d->player.direccion_y = -1;
		cub3d->player.direccion_x = 0;
	}
	else if (pos_player == 'S')
	{
		cub3d->player.direccion_y = 0;
		cub3d->player.direccion_x = 1;
	}
	else if (pos_player == 'W')
	{
		cub3d->player.direccion_y = 1;
		cub3d->player.direccion_x = 0;
	}
	else
		printf("Error\n");
}

static double	fill_raydirx(t_cub3d *cub3d, int x)
{
	double	raydir_x;
	double	camera;
	double	plane_x;

	camera = 0;
	plane_x = -cub3d->player.direccion_y * 0.66;
	camera = 2 * x / (double) SCREEN_WIDTH -1;
	raydir_x = cub3d->player.direccion_x + plane_x * camera;
	return (raydir_x);
}

static double	fill_raydiry(t_cub3d *cub3d, int x)
{
	double	raydir_y;
	double	camera;
	double	plane_y;

	camera = 0;
	plane_y = cub3d->player.direccion_x * 0.66;
	camera = 2 * x / (double) SCREEN_WIDTH -1;
	raydir_y = cub3d->player.direccion_y + plane_y * camera;
	return (raydir_y);
}

void	raycast(t_cub3d *cub3d)
{
	int		x;
	double	ratio_x;
	double	ratio_y;
	int	map_x;
	int	map_y;

	map_x = (int)cub3d->player.x_position;
	map_y = (int)cub3d->player.y_position;
	render_ceiling_floor(cub3d);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		cub3d->raycast.raydir_x = fill_raydirx(cub3d, x);
		cub3d->raycast.raydir_y = fill_raydiry(cub3d, x); 
		ratio_x = cub3d->raycast.raydir_y / cub3d->raycast.raydir_x;
		ratio_y = cub3d->raycast.raydir_x / cub3d->raycast.raydir_y;
		cub3d->raycast.delta_dist_x = sqrt(1 + ratio_x * ratio_x);
		cub3d->raycast.delta_dist_y = sqrt(1 + ratio_y * ratio_y);
		step_direccion(cub3d, map_x, map_y);
		dda_loop(cub3d, map_x, map_y);
		print_cub3d(cub3d, x);
		x++;
	}
	render_buffer_to_window(cub3d);
}
