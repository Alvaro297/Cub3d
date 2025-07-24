#include "../cub3d.h"

static void	change_angle(t_cub3d *cub3d, int keycode)
{
	double	rot_speed;

	rot_speed = 0.02;
	if (keycode == 65363)
		cub3d->player.angle += rot_speed;
	else if (keycode == 65361)
		cub3d->player.angle -= rot_speed;
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
	int	yi;
	int	xi;

	yi = (int)y;
	xi = (int)x;
	if (yi < 0 || yi >= cub3d->map.height || xi < 0 || xi >= cub3d->map.width)
		return (true);
	if (xi >= (int)ft_strlen(cub3d->map.matriz[yi]))
		return (true);
	return (cub3d->map.matriz[yi][xi] == '1');
}

int	ft_key_hook(t_cub3d *cub3d)
{
	bool movement_occurred = false;
	double old_x;
	double old_y;
	
	if (cub3d->player.movement.left)
	{
		change_angle(cub3d, 65361);
		movement_occurred = true;
	}
	if (cub3d->player.movement.right)
	{
		change_angle(cub3d, 65363);
		movement_occurred = true;
	}
	old_x = cub3d->player.x_position;
	old_y = cub3d->player.y_position;
	movement_player(cub3d);
	if (movement_occurred || 
		old_x != cub3d->player.x_position || 
		old_y != cub3d->player.y_position)
		raycast(cub3d);
	
	return (0);
}

static void	rotate_player(t_cub3d *cub3d, double rot)
{
	cub3d->player.angle += rot;
	if (cub3d->player.angle < 0)
		cub3d->player.angle += 2 * M_PI;
	if (cub3d->player.angle >= 2 * M_PI)
		cub3d->player.angle -= 2 * M_PI;
	cub3d->player.direccion_x = cos(cub3d->player.angle);
	cub3d->player.direccion_y = sin(cub3d->player.angle);
}

int ft_mouse_hook(int x, int y, t_cub3d *cub3d)
{
	static int	last_x = -1;
	static int	frame_count = 0;
	double		speed_rotate;
	double		rot;

	(void)y;
	speed_rotate = 0.003;
	frame_count++;
	if (frame_count % 15 != 0)
		return (0);
	
	if (last_x != -1)
	{
		if (abs(x - last_x) > 2)
		{
			rot = (x - last_x) * speed_rotate;
			rotate_player(cub3d, rot);
			raycast(cub3d);
		}
	}
	last_x = x;
	return (0);
}
