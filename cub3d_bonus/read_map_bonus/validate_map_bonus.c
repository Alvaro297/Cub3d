#include "../cub3d_bonus.h"

static int	flood_fill(char **map, int x, int y, int height)
{
	if (y < 0 || y >= height || x < 0 || x >= (int)ft_strlen(map[y]))
		return (0);
	if (map[y][x] == ' ' || map[y][x] == '\0')
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'x')
		return (1);
	map[y][x] = 'x';
	if (!flood_fill(map, x + 1, y, height))
		return (0);
	if (!flood_fill(map, x - 1, y, height))
		return (0);
	if (!flood_fill(map, x, y + 1, height))
		return (0);
	if (!flood_fill(map, x, y - 1, height))
		return (0);
	return (1);
}

static void	fill_spaces(char *line, int start, int width)
{
	while (start < width)
	{
		line[start] = ' ';
		start++;
	}
	line[width] = '\0';
}

static char	**normalize_map(char **map, t_cub3d *cub3d)
{
	int		height;
	char	**norm;
	int		y;

	height = 0;
	cub3d->map.width = 0;
	while (map[height])
	{
		if ((int)ft_strlen(map[height]) > cub3d->map.width)
			cub3d->map.width = ft_strlen(map[height]);
		height++;
	}
	norm = malloc(sizeof(char *) * (height + 1));
	if (!norm)
		return (NULL);
	y = -1;
	while (++y < height)
	{
		norm[y] = malloc(cub3d->map.width + 1);
		if (!norm[y])
			return (free_norm_map(norm, y), NULL);
		ft_strlcpy(norm[y], map[y], cub3d->map.width + 1);
		fill_spaces(norm[y], ft_strlen(map[y]), cub3d->map.width);
	}
	norm[height] = NULL;
	return (norm);
}

void	validate_map(t_cub3d *cub3d)
{
	int		x;
	int		y;
	char	**map_copy;

	cub3d->map.height = 0;
	while (cub3d->map.matriz[cub3d->map.height])
		cub3d->map.height++;
	map_copy = normalize_map(cub3d->map.matriz, cub3d);
	if (!map_copy)
	{
		printf("Error\nFailed to allocate map copy\n");
		free_cub3d(cub3d);
		exit(1);
	}
	y = -1;
	while (map_copy[++y])
	{
		x = -1;
		while (map_copy[y][++x])
			validate_cell(cub3d, map_copy, y, x, cub3d->map.height);
	}
	ft_free_map(map_copy, cub3d);
}

void	validate_cell(t_cub3d *cub3d, char **map_copy,
				int y, int x, int height)
{
	char	c;
	char	**map_region;

	c = map_copy[y][x];
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != '0')
		return ;
	map_region = normalize_map(map_copy, cub3d);
	if (!flood_fill(map_region, x, y, height))
	{
		printf("Error\nMap is not closed\n");
		ft_free_map(map_region, cub3d);
		ft_free_map(map_copy, cub3d);
		free_cub3d(cub3d);
		exit(1);
	}
	cub3d->map.matriz_norm = map_region;
}
