/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 22:20:13 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-10 22:20:13 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	change_angle(t_cub3d *cub3d, int keycode)
{
	double	rot_speed;

	rot_speed = 0.05;
	if (keycode == 65361)
		cub3d->player.angle += rot_speed;
	else if (keycode == 65363)
		cub3d->player.angle -= rot_speed;
	if (cub3d->player.angle < 0)
		cub3d->player.angle += 2 * 3.14159265359;
	if (cub3d->player.angle >= 2 * 3.14159265359)
		cub3d->player.angle -= 2 * 3.14159265359;
	cub3d->player.direccion_x = cos(cub3d->player.angle);
	cub3d->player.direccion_y = sin(cub3d->player.angle);
}

int	key_press(int keycode, t_cub3d *cub3d)
{
	if (keycode == 119 || keycode == 'w')
		cub3d->player.movement.w = true;
	else if (keycode == 115 || keycode == 's')
		cub3d->player.movement.s = true;
	else if (keycode == 97 || keycode == 'a')
		cub3d->player.movement.a = true;
	else if (keycode == 100 || keycode == 'd')
		cub3d->player.movement.d = true;
	else if (keycode == KEY_E)
		open_door(cub3d);
	else if (keycode == 65361)
		cub3d->player.movement.left = true;
	else if (keycode == 65363)
		cub3d->player.movement.right = true;
	else if (keycode == 65307)
	{
		free_cub3d(cub3d);
		return (exit(0), 0);
	}
	return (0);
}

int	key_release(int keycode, t_cub3d *cub3d)
{
	if (keycode == 119 || keycode == 'w')
		cub3d->player.movement.w = false;
	else if (keycode == 115 || keycode == 's')
		cub3d->player.movement.s = false;
	else if (keycode == 97 || keycode == 'a')
		cub3d->player.movement.a = false;
	else if (keycode == 100 || keycode == 'd')
		cub3d->player.movement.d = false;
	else if (keycode == 65361)
		cub3d->player.movement.left = false;
	else if (keycode == 65363)
		cub3d->player.movement.right = false;
	return (0);
}

bool	is_wall(t_cub3d *cub3d, double x, double y)
{
	int		yi;
	int		xi;
	t_door	*door;
	char	cell;

	cell = '\0';
	xi = (int)x;
	yi = (int)y;
	door = NULL;
	if (yi < 0 || yi >= cub3d->map.height || xi < 0 || xi >= cub3d->map.width)
		return (true);
	if (xi >= (int)ft_strlen(cub3d->map.matriz[yi]))
		return (true);
	cell = cub3d->map.matriz[yi][xi];
	if (cell == '1')
		return (true);
	else if (cell == '2')
	{
		door = get_door(cub3d, xi, yi);
		if (!door || door->animation < 0.99)
			return (true);
	}
	return (false);
}

int	ft_key_hook(t_cub3d *cub3d)
{
	if (cub3d->player.movement.right)
		change_angle(cub3d, 65361);
	if (cub3d->player.movement.left)
		change_angle(cub3d, 65363);
	movement_player(cub3d);
	update_doors(cub3d);
	ft_animation(cub3d);
	raycast(cub3d);
	draw_minimap(cub3d);
	return (0);
}
