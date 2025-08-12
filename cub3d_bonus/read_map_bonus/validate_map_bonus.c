/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 23:12:47 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-10 23:12:47 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	height = -1;
	cub3d->map.width = 0;
	while (map[++height])
	{
		if ((int)ft_strlen(map[height]) > cub3d->map.width)
			cub3d->map.width = ft_strlen(map[height]);
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

static void	validate_cell(t_cub3d *cub3d, char **map_copy,
				int y, int x)
{
	char	c;
	char	**map_region;
	char	**map_region_copy;
	int		height;

	map_region_copy = NULL;
	height = cub3d->map.height;
	c = map_copy[y][x];
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != '0')
		return ;
	map_region = normalize_map(map_copy, cub3d);
	map_region_copy = copy_region(map_region, cub3d);
	if (!map_region_copy || !flood_fill(map_region_copy, x, y, height))
	{
		printf("Error\nMap is not closed\n");
		if (map_region_copy)
			free_norm_map(map_region_copy, cub3d->map.height);
		ft_free_map(map_region, cub3d);
		ft_free_map(map_copy, cub3d);
		free_cub3d(cub3d);
		exit(1);
	}
	validate_cell_help(cub3d, map_region, map_region_copy);
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
			validate_cell(cub3d, map_copy, y, x);
	}
	ft_free_map(map_copy, cub3d);
}
