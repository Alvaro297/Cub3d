# include "../cub3d.h"

static void	step_direccion(t_cub3d *cub3d, t_raycasting *raycast, int x)
{
	int	map_x;
	int	map_y;

	map_x = (int)cub3d->player.x_position;
	map_y = (int)cub3d->player.y_position;
	if (raycast->raydir_x[x] < 0)
	{
		raycast->step_x[x] = -1;
		raycast->sideDist_x[x] = (cub3d->player.x_position - map_x) * raycast->delta_dist_x[x];
	}
	else
	{
		raycast->step_x[x] = 1;
		raycast->sideDist_x[x] = (map_x + 1.0 - cub3d->player.x_position) * raycast->delta_dist_x[x];
	}
	if (raycast->raydir_y[x] < 0)
	{
		raycast->step_y[x] = -1;
		raycast->sideDist_y[x] = (cub3d->player.y_position - map_y) * raycast->delta_dist_y[x];
	}
	else
	{
		raycast->step_y[x] = 1;
		raycast->sideDist_y[x] = (map_y + 1.0 - cub3d->player.y_position) * raycast->delta_dist_y[x];
	}
}

void	steps(t_cub3d *cub3d)
{
	int	x;

	cub3d->raycast.step_x = malloc(sizeof(short) * SCREEN_WIDTH);
	cub3d->raycast.step_y = malloc(sizeof(short) * SCREEN_WIDTH);
	cub3d->raycast.sideDist_x = malloc(sizeof(double) * SCREEN_WIDTH);
	cub3d->raycast.sideDist_y = malloc(sizeof(double) * SCREEN_WIDTH);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		step_direccion(cub3d, &cub3d->raycast, x);
		x++;
	}
}
