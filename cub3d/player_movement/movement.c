/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-07 18:53:44 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-07 18:53:44 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	move_front(t_cub3d *cub3d, double move_speed, double margin)
{
	double	new_x;
	double	new_y;

	new_x = cub3d->player.x_position + cub3d->player.direccion_x * move_speed;
	new_y = cub3d->player.y_position + cub3d->player.direccion_y * move_speed;
	if (!is_wall(cub3d, new_x + cub3d->player.direccion_x * margin,
			cub3d->player.y_position))
		cub3d->player.x_position = new_x;
	if (!is_wall(cub3d, cub3d->player.x_position, new_y
			+ cub3d->player.direccion_y * margin))
		cub3d->player.y_position = new_y;
}

static void	move_back(t_cub3d *cub3d, double move_speed, double margin)
{
	double	new_x;
	double	new_y;

	new_x = cub3d->player.x_position - cub3d->player.direccion_x * move_speed;
	new_y = cub3d->player.y_position - cub3d->player.direccion_y * move_speed;
	if (!is_wall(cub3d, new_x - cub3d->player.direccion_x * margin,
			cub3d->player.y_position))
		cub3d->player.x_position = new_x;
	if (!is_wall(cub3d, cub3d->player.x_position, new_y
			- cub3d->player.direccion_y * margin))
		cub3d->player.y_position = new_y;
}

static void	move_right(t_cub3d *cub3d, double move_speed, double margin)
{
	double	new_x;
	double	new_y;

	new_x = cub3d->player.x_position + cub3d->player.direccion_y * move_speed;
	new_y = cub3d->player.y_position - cub3d->player.direccion_x * move_speed;
	if (!is_wall(cub3d, new_x + cub3d->player.direccion_y * margin,
			cub3d->player.y_position))
		cub3d->player.x_position = new_x;
	if (!is_wall(cub3d, cub3d->player.x_position, new_y
			- cub3d->player.direccion_x * margin))
		cub3d->player.y_position = new_y;
}

static void	move_left(t_cub3d *cub3d, double move_speed, double margin)
{
	double	new_x;
	double	new_y;

	new_x = cub3d->player.x_position - cub3d->player.direccion_y * move_speed;
	new_y = cub3d->player.y_position + cub3d->player.direccion_x * move_speed;
	if (!is_wall(cub3d, new_x - cub3d->player.direccion_y * margin,
			cub3d->player.y_position))
		cub3d->player.x_position = new_x;
	if (!is_wall(cub3d, cub3d->player.x_position, new_y
			+ cub3d->player.direccion_x * margin))
		cub3d->player.y_position = new_y;
}

void	movement_player(t_cub3d *cub3d)
{
	double	move_speed;
	double	margin;

	margin = 0.4;
	move_speed = 0.03;
	if (cub3d->player.movement.w)
		move_front(cub3d, move_speed, margin);
	if (cub3d->player.movement.s)
		move_back(cub3d, move_speed, margin);
	if (cub3d->player.movement.d)
		move_left(cub3d, move_speed, margin);
	if (cub3d->player.movement.a)
		move_right(cub3d, move_speed, margin);
}
