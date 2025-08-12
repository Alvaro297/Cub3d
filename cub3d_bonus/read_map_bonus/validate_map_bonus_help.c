/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus_help.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-12 21:31:03 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-12 21:31:03 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	**copy_region(char **map_region, t_cub3d *cub3d)
{
	int		i;
	int		height;
	char	**map_region_copy;

	height = 0;
	while (map_region[height])
		height++;
	map_region_copy = malloc(sizeof(char *) * (height + 1));
	if (!map_region_copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map_region_copy[i] = malloc(cub3d->map.width + 1);
		if (!map_region_copy[i])
		{
			free_norm_map(map_region_copy, i);
			return (NULL);
		}
		ft_strlcpy(map_region_copy[i], map_region[i], cub3d->map.width + 1);
		i++;
	}
	map_region_copy[height] = NULL;
	return (map_region_copy);
}

static void	good_map(char **map_region, char **map_region_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_region[i])
	{
		j = 0;
		while (map_region[i][j])
		{
			if (map_region_copy[i][j] == 'x' && map_region[i][j] == '0')
				map_region[i][j] = 'x';
			j++;
		}
		i++;
	}
}

void	validate_cell_help(t_cub3d *cub3d,
			char **map_region, char **map_region_copy)
{
	if (cub3d->map.matriz_norm)
		ft_free_map(cub3d->map.matriz_norm, cub3d);
	good_map(map_region, map_region_copy);
	if (map_region_copy)
		free_norm_map(map_region_copy, cub3d->map.height);
	cub3d->map.matriz_norm = map_region;
}
