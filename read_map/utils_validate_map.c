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
}

int	is_closed(char **map, int x, int y)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	if (y == 0 || y == height - 1 || x == 0 || x == (int)ft_strlen(map[y]) - 1)
		return (0);
	if (!map[y - 1] || !map[y + 1])
		return (0);
	if (!map[y][x - 1] || !map[y][x + 1])
		return (0);
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' '
		|| map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
		return (0);
	return (1);
}

int	check_texture_file(const char *path)
{
	int		fd;
	char	buf;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCannot open texture file: %s\n", path);
		return (1);
	}
	if (read(fd, &buf, 1) <= 0)
	{
		printf("Error\nTexture file\n");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	check_texture_name(const char *path, const char *expected)
{
	size_t	len;

    len = ft_strlen(path);
	if (!ft_strnstr(path, expected, len))
        return (printf("Error\nIn texture name\n"), 1);
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
        return (printf("Error\nIn texture extension\n"), 1);
	return (0);
}
