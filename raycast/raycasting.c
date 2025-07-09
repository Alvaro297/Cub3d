#include "../cub3d.h"

static void	starting_raycasting(t_cub3d *cub3d, char pos_player)
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

static double	*fill_raydirx(t_cub3d *cub3d)
{
	double	*raydir_x;
	double	camera;
	int		i;
	double	plane_x;

	i = 0;
	raydir_x = malloc(sizeof(double) * SCREEN_WIDTH);
	camera = 0;
	plane_x = -cub3d->player.direccion_x * 0.66;
	while (i < SCREEN_WIDTH)
	{
		camera = 2 * i / (double) SCREEN_WIDTH -1;
		raydir_x[i] = cub3d->player.direccion_x + plane_x * camera;
		i++;
	}
	return (raydir_x);
}

static double	*fill_raydiry(t_cub3d *cub3d)
{
	double *raydir_y;
	double camera;
	int i;
	double	plane_y;

	raydir_y = malloc(sizeof(double) * SCREEN_WIDTH);
	i = 0;
	camera = 0;
	plane_y = -cub3d->player.direccion_y * 0.66;
	while (i < SCREEN_WIDTH)
	{
		camera = 2 * i / (double)SCREEN_WIDTH - 1;
		raydir_y[i] = cub3d->player.direccion_y + plane_y * camera;
		i++;
	}
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
	x = 0;
	starting_raycasting(cub3d, cub3d->player.direction);
	while (x < SCREEN_WIDTH)
	{
		ratio_x = cub3d->raycast.raydir_y / cub3d->raycast.raydir_x;
		ratio_y = cub3d->raycast.raydir_x / cub3d->raycast.raydir_y;
		cub3d->raycast.delta_dist_x = sqrt(1 + ratio_x * ratio_x);
		cub3d->raycast.delta_dist_y = sqrt(1 + ratio_y * ratio_y);
		step_direccion(cub3d, map_x, map_y);
		dda_loop(cub3d, map_x, map_y);
		print_cub3d(cub3d);
		x++;
	}
}
