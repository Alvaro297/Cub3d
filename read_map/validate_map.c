#include "./cub3d.h"

void	set_player(t_cub3d *cub3d, int x, int y, char dir)
{
	cub3d->player.x_position = x;
	cub3d->player.y_position = y;
	cub3d->player.direction = dir;
	if (dir == 'N')
		cub3d->player.angle = 90.0;
	else if (dir == 'S')
		cub3d->player.angle = 270.0;
	else if (dir == 'E')
		cub3d->player.angle = 0.0;
	else if (dir == 'W')
		cub3d->player.angle = 180.0;
	/* printf(
		"Jugador:\n"
		"  Posición X: %d\n"
		"  Posición Y: %d\n"
		"  Ángulo: %.1f\n"
		"  Nº de jugar %d\n"
		"  Dirección: %c\n",
		x, y, cub3d->player.angle, cub3d->player.player_count, dir
	); */

}

int	is_closed(char **map, int x, int y)
{
	if (!map[y - 1] || !map[y + 1])
		return (0);
	if (!map[y][x - 1] || !map[y][x + 1])
		return (0);
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' '
		|| map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
		return (0);
	return (1);
}

void	validate_map(t_cub3d *cub3d)
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
				(set_player(cub3d, x, y, c), cub3d->player.player_count++);
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
				|| c == '\0')
			{
				if (!is_closed(cub3d->map.matriz, x, y))
					(printf("Error\nMap is not closed\n"), exit(1));
			}
			x++;
		}
		y++;
	}
	if (cub3d->player.player_count != 1)
		(printf("Error\nincorrect nº of player\n"), exit(1));
}
