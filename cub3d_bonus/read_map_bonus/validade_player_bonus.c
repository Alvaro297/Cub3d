/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validade_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 23:12:58 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-10 23:12:58 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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

	y = -1;
	while (cub3d->map.matriz[++y])
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
	}
	if (cub3d->player.player_count != 1)
	{
		printf("Error\nincorrect nº of player\n");
		free_cub3d(cub3d);
		exit(1);
	}
}
