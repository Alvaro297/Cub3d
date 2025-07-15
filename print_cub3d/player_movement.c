#include "../cub3d.h"

static void	change_angle(t_cub3d *cub3d, int keycode)
{
	double	rot_speed;

	rot_speed = 0.01;
	if (keycode == 65361)
		cub3d->player.angle -= rot_speed;
	else if (keycode == 65363)
		cub3d->player.angle += rot_speed;
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
	else if (keycode == 65361)
		cub3d->player.movement.left = true;
	else if (keycode == 65363)
		cub3d->player.movement.right = true;
	else if (keycode == 65307)
	{
		free_cub3d(cub3d);
		return(exit(0), 0);
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

int	ft_key_hook(t_cub3d *cub3d)
{
	double	move_speed;
	
	move_speed= 0.005;
	if (cub3d->player.movement.w)
	{
		cub3d->player.x_position += cub3d->player.direccion_x * move_speed;
		cub3d->player.y_position += cub3d->player.direccion_y * move_speed;
	}
	if (cub3d->player.movement.s)
	{
		cub3d->player.x_position -= cub3d->player.direccion_x * move_speed;
		cub3d->player.y_position -= cub3d->player.direccion_y * move_speed;
	}
	if (cub3d->player.movement.a)
	{
		cub3d->player.x_position += cub3d->player.direccion_y * move_speed;
		cub3d->player.y_position -= cub3d->player.direccion_x * move_speed;
	}
	if (cub3d->player.movement.d)
	{
		cub3d->player.x_position -= cub3d->player.direccion_y * move_speed;
		cub3d->player.y_position += cub3d->player.direccion_x * move_speed;
	}
	if (cub3d->player.movement.left)
		change_angle(cub3d, 65361);
	if (cub3d->player.movement.right)
		change_angle(cub3d, 65363);

	raycast(cub3d);
	return (0);
}

int ft_mouse_hook(int x, t_cub3d *cub3d)
{
	static int	last_x = -1;
	double	speed_rotate;
	double	rot;

	speed_rotate = 0.1;
	if (last_x != -1)
	{
		rot = (x - last_x) * speed_rotate;
		cub3d->player.angle += rot;
		cub3d->player.direccion_x = cos(cub3d->player.angle);
		cub3d->player.direccion_y = sin(cub3d->player.angle);
	}
	last_x = x;
	raycast(cub3d);
	return (0);
}
