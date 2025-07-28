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
	double	right_x;
	double	right_y;

	right_x = cub3d->player.direccion_y;
	right_y = -cub3d->player.direccion_x;
	new_x = cub3d->player.x_position + right_x * move_speed;
	new_y = cub3d->player.y_position + right_y * move_speed;
	if (!is_wall(cub3d, new_x + right_x * margin, cub3d->player.y_position))
		cub3d->player.x_position = new_x;
	if (!is_wall(cub3d, cub3d->player.x_position, new_y + right_y * margin))
		cub3d->player.y_position = new_y;
}

static void	move_left(t_cub3d *cub3d, double move_speed, double margin)
{
	double	new_x;
	double	new_y;
	double	left_x;
	double	left_y;

	
	left_x = -cub3d->player.direccion_y;
	left_y = cub3d->player.direccion_x;
	new_x = cub3d->player.x_position + left_x * move_speed;
	new_y = cub3d->player.y_position + left_y * move_speed;
	if (!is_wall(cub3d, new_x + left_x * margin, cub3d->player.y_position))
		cub3d->player.x_position = new_x;
	if (!is_wall(cub3d, cub3d->player.x_position, new_y + left_y * margin))
		cub3d->player.y_position = new_y;
}

void	movement_player(t_cub3d *cub3d)
{
	double	move_speed;
	double	margin;

	margin = 0.30;
	move_speed = 0.03;
	if (is_wall(cub3d, cub3d->player.x_position + cub3d->player.direccion_x * 0.5, 
				cub3d->player.y_position) ||
		is_wall(cub3d, cub3d->player.x_position, 
				cub3d->player.y_position + cub3d->player.direccion_y * 0.5))
		move_speed *= 0.5;
	if (cub3d->player.movement.w)
		move_front(cub3d, move_speed, margin);
	if (cub3d->player.movement.s)
		move_back(cub3d, move_speed, margin);
	if (cub3d->player.movement.d)
		move_left(cub3d, move_speed, margin);
	if (cub3d->player.movement.a)
		move_right(cub3d, move_speed, margin);
}
