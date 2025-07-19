#include "./cub3d.h"

void	set_player(t_cub3d *cub3d, int x, int y, char dir)
{
	cub3d->player.x_position = (double) x + 0.5;
	cub3d->player.y_position = (double) y + 0.5;
	cub3d->player.direction = dir;
	if (dir == 'N')
		cub3d->player.angle = 90.0;
	else if (dir == 'S')
		cub3d->player.angle = 270.0;
	else if (dir == 'E')
		cub3d->player.angle = 0.0;
	else if (dir == 'W')
		cub3d->player.angle = 180.0;
}

void	check_player(t_cub3d *cub3d)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (cub3d->map.matriz[y])
	{
		x = 0;
		while (cub3d->map.matriz[y][x])
		{
			c = cub3d->map.matriz[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				set_player(cub3d, x, y, c);
				cub3d->player.player_count++;
			}
			x++;
		}
		y++;
	}
	if (cub3d->player.player_count != 1)
	{
		printf("Error\nincorrect nº of player\n");
		free_cub3d(cub3d);
		exit(1);
	}
}
