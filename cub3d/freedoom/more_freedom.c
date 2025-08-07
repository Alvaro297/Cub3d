/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_freedom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-07 18:54:24 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-07 18:54:24 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_matriz(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map.matriz[i])
	{
		free(cub3d->map.matriz[i]);
		i++;
	}
	free(cub3d->map.matriz);
}

void	free_norm_matriz(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map.matriz_norm[i])
	{
		free(cub3d->map.matriz_norm[i]);
		i++;
	}
	free(cub3d->map.matriz_norm);
}

int	close_window(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	free_cub3d(cub3d);
	exit(0);
	return (0);
}

void	free_norm_map(char **map, int upto)
{
	int	i;

	i = 0;
	while (i < upto)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_map(char **map_lines, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	if (!map_lines)
		return ;
	while (i < cub3d->map.map_index)
	{
		if (map_lines[i])
		{
			free(map_lines[i]);
			map_lines[i++] = NULL;
		}
		else
			i++;
	}
	if (map_lines)
		free(map_lines);
	map_lines = NULL;
}
