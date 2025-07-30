#include "../cub3d_bonus.h"

void	starting_raycasting(t_cub3d *cub3d, char pos_player)
{
	if (pos_player == 'N')
	{
		cub3d->player.direccion_y = -1;
		cub3d->player.direccion_x = 0;
	}
	else if (pos_player == 'E')
	{
		cub3d->player.direccion_y = 0;
		cub3d->player.direccion_x = 1;
	}
	else if (pos_player == 'S')
	{
		cub3d->player.direccion_y = 1;
		cub3d->player.direccion_x = 0;
	}
	else if (pos_player == 'W')
	{
		cub3d->player.direccion_y = 0;
		cub3d->player.direccion_x = -1;
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
	int	map_x;
	int	map_y;

	render_ceiling_floor(cub3d);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		map_x = (int)cub3d->player.x_position;
		map_y = (int)cub3d->player.y_position;
		cub3d->raycast.raydir_x = fill_raydirx(cub3d, x);
		cub3d->raycast.raydir_y = fill_raydiry(cub3d, x);
		if (cub3d->raycast.raydir_x == 0)
			cub3d->raycast.delta_dist_x = 1e30;
		else
			cub3d->raycast.delta_dist_x = fabs(1.0 / cub3d->raycast.raydir_x);
		if (cub3d->raycast.raydir_y == 0)
			cub3d->raycast.delta_dist_y = 1e30;
		else
			cub3d->raycast.delta_dist_y = fabs(1.0 / cub3d->raycast.raydir_y);
		step_direccion(cub3d, map_x, map_y);
		dda_loop(cub3d, map_x, map_y);
		print_cub3d(cub3d, x);
		x++;
	}
}
