# include "../cub3d.h"

void	steps(t_cub3d *cub3d)
{
	int	x;

	cub3d->raycast.step_x = malloc(sizeof(short) * SCREEN_WIDTH);
	cub3d->raycast.step_y = malloc(sizeof(short) * SCREEN_WIDTH);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		if (cub3d->raycast.raydir_x[x] > 0)
			cub3d->raycast.step_x[x] = 1
		else
			cub3d->raycast.step_x[x] = -1;
		if (cub3d->raycast.raydir_y[y] > 0)
			cub3d->raycast.step_y[x] = 1;
		else
			cub3d->raycast.step_y[x] = -1;
		x++;
	}
}
