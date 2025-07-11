#include "../cub3d.h"

static void	change_angle(t_cub3d *cub3d, int keycode)
{
	double	rot_speed;

	rot_speed = 0.07;
	if (keycode == 123) // Flecha izquierda
		cub3d->player.angle -= rot_speed;
	else if (keycode == 124) // Flecha derecha
		cub3d->player.angle += rot_speed;
	cub3d->player.direccion_x = cos(cub3d->player.angle);
	cub3d->player.direccion_y = sin(cub3d->player.angle);
}

int ft_key_hook(int keycode, t_cub3d *cub3d)
{
	double	move_speed;

	move_speed = 0.1;
	if (keycode == 13)
		cub3d->player.x_position += cub3d->player.direccion_x * move_speed;
	else if (keycode == 1)
		cub3d->player.x_position -= cub3d->player.direccion_x * move_speed;
	else if (keycode == 0)
		cub3d->player.y_position -= cub3d->player.direccion_y * move_speed;
	else if (keycode == 2)
		cub3d->player.y_position += cub3d->player.direccion_y * move_speed;
	else if (keycode == 123)
		change_angle(cub3d, keycode);
	else if (keycode == 124)
		change_angle(cub3d, keycode);
	else if (keycode == 65307)
	{
		free_cub3d(cub3d);
		return(exit(0), 0);
	}
	else
		return (0);
	raycast(cub3d);
	print_cub3d(cub3d, 0);
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
	print_cub3d(cub3d, 0);
	return (0);
}
