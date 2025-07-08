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
	else if (pos_player == 4)
	{
		cub3d->player.direccion_y = 1;
		cub3d->player.direccion_x = 0;
	}
	else
		printf("Error\n");
}

float	*fill_raydirx(t_cub3d *cub3d)
{
	float	*raydir_x;
	float	camera;
	int		i;
	float	plane_x;

	i = 0;
	raydir_x = malloc(sizeof(float) * SCREEN_WIDTH);
	camera = 0;
	plane_x = -cub3d->player.x_position * 0.66;
	while (i < SCREEN_WIDTH)
	{
		camera = 2 * i / (float) SCREEN_WIDTH -1;
		raydir_x[i] = cub3d->player.direccion_x + plane_x * camera;
		i++;
	}
	return (raydir_x);
}

float *fill_raydiry(t_cub3d *cub3d)
{
	float *raydir_y;
	float camera;
	int i;
	float	plane_y;

	raydir_y = malloc(sizeof(float) * SCREEN_WIDTH);
	i = 0;
	camera = 0;
	plane_y = -cub3d->player.y_position * 0.66;
	while (i < SCREEN_WIDTH)
	{
		camera = 2 * i / (float)SCREEN_WIDTH - 1;
		raydir_y[i] = cub3d->player.direccion_y + plane_y * camera;
		i++;
	}
	return (raydir_y);
}

void	init_raycast(t_cub3d *cub3d)
{
	float	*raydir_x;
	float	*raydir_y;

	starting_raycasting(cub3d, cub3d->player.direction);
	raydir_x = fill_raydirx(cub3d);
	raydir_y = fill_raydirxy(cub3d);
}
