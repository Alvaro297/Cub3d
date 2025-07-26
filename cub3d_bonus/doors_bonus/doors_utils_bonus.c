#include "../cub3d_bonus.h"

void	update_doors(t_cub3d *cub3d)
{
	int		i;
	t_door	*door;

	double dx, dy, distance;
	i = 0;
	while (i < cub3d->map.n_doors)
	{
		door = &cub3d->map.door[i];
		// Animar apertura o cierre
		if (door->is_open && door->animation < 1.0)
			door->animation += 0.05;
		else if (!door->is_open && door->animation > 0.0)
			door->animation -= 0.05;
		if (door->is_open)
		{
			dx = cub3d->player.x_position - door->x - 0.5;
			dy = cub3d->player.y_position - door->y - 0.5;
			distance = sqrt(dx * dx + dy * dy);
			if (distance > 1.2)
			{
				door->is_open = false;
				door->animation = 1.0;
				printf("[DEBUG] Cerrando puerta automáticamente en (%d, %d)\n",
					door->x, door->y);
			}
		}
		i++;
	}
}

void	toogle_door(t_cub3d *cub3d)
{
	int		i;
	double	px;
	double	py;
	t_door	*door;
	double	dx;
	double	dy;
	double	distance;

	px = cub3d->player.x_position;
	i = 0;
	py = cub3d->player.y_position;
	while (i < cub3d->map.n_doors)
	{
		door = &cub3d->map.door[i];
		dx = px - door->x;
		dy = py - door->y;
		distance = dx * dx + dy * dy;
		if (distance < 1.5 * 1.5)
		{
			door->is_open = !door->is_open;
			break ;
		}
		i++;
	}
}
