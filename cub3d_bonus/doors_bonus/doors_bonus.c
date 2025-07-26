#include "../cub3d_bonus.h"

static void	door_position(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	cub3d->map.door = malloc(sizeof(t_door) * cub3d->map.n_doors);
	if (!cub3d->map.door)
		(printf("Error\nmalloc in doors failed\n"), free_cub3d(cub3d), exit(1));
	while (i < cub3d->map.height)
	{
		j = 0;
		while (j < cub3d->map.width)
		{
			if (cub3d->map.matriz_norm[i][j] == '2')
			{
				cub3d->map.door[k].x = j;
				cub3d->map.door[k].y = i;
				cub3d->map.door[k].is_open = false;
				cub3d->map.door[k].animation = 0.0;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	find_doors(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	cub3d->map.n_doors = 0;
	while (i < cub3d->map.height)
	{
		j = 0;
		while (j < cub3d->map.width)
		{
			if (cub3d->map.matriz_norm[i][j] == '2')
				cub3d->map.n_doors++;
			j++;
		}
		i++;
	}
	door_position(cub3d);
}

void	open_door(t_cub3d *cub3d)
{
	int	dx;
	int	dy;
	int	i;

	dx = (int)(cub3d->player.x_position + cub3d->player.direccion_x);
	dy = (int)(cub3d->player.y_position + cub3d->player.direccion_y);
	i = 0;
	while (i < cub3d->map.n_doors)
	{
		if (cub3d->map.door[i].x == dx && cub3d->map.door[i].y == dy)
		{
			cub3d->map.door[i].is_open = !cub3d->map.door[i].is_open;
			if (cub3d->map.door[i].is_open)
				cub3d->map.door[i].animation = 1.0;
			else
				cub3d->map.door[i].animation = 0.0;

			break;
		}
		i++;
	}
	update_doors(cub3d); 
	raycast(cub3d);
	draw_minimap(cub3d);
}

t_door	*get_door(t_cub3d *cub3d, int x, int y)
{
	int	i;

	i = 0;
	while (i < cub3d->map.n_doors)
	{
		if (cub3d->map.door[i].x == x && cub3d->map.door[i].y == y)
			return (&cub3d->map.door[i]);
		i++;
	}
	return (NULL);
}
