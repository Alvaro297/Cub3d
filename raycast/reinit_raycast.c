#include "../cub3d.h"

void	reinit_raycast(t_cub3d *cub3d)
{
	cub3d->raycast.raydir_x = fill_raydirx(cub3d);
	cub3d->raycast.raydir_y = fill_raydiry(cub3d);
	cub3d->raycast.delta_dist_x = malloc(sizeof(double) * SCREEN_WIDTH);
	cub3d->raycast.delta_dist_y = malloc(sizeof(double) * SCREEN_WIDTH);
	cub3d->raycast.step_x = malloc(sizeof(short) * SCREEN_WIDTH);
	cub3d->raycast.step_y = malloc(sizeof(short) * SCREEN_WIDTH);
	cub3d->raycast.sideDist_x = malloc(sizeof(double) * SCREEN_WIDTH);
	cub3d->raycast.sideDist_y = malloc(sizeof(double) * SCREEN_WIDTH);
	cub3d->raycast.wall_hit_x = malloc(sizeof(double) * SCREEN_WIDTH);
	cub3d->raycast.wall_hit_y = malloc(sizeof(double) * SCREEN_WIDTH);
	cub3d->raycast.perp_wall_dist = malloc(sizeof(double) * SCREEN_WIDTH);
	cub3d->raycast.is_horizontal = malloc(sizeof(bool) * SCREEN_WIDTH);
	cub3d->raycast.hit_type = malloc(sizeof(char) * SCREEN_WIDTH);
}

void	free_raycast(t_cub3d *cub3d)
{
	if (cub3d->raycast.raydir_x)
		free(cub3d->raycast.raydir_x);
	if (cub3d->raycast.raydir_y)
		free(cub3d->raycast.raydir_y);
	if (cub3d->raycast.delta_dist_x)
		free(cub3d->raycast.delta_dist_x);
	if (cub3d->raycast.delta_dist_y)
		free(cub3d->raycast.delta_dist_y);
	if (cub3d->raycast.step_x)
		free(cub3d->raycast.step_x);
	if (cub3d->raycast.step_y)
		free(cub3d->raycast.step_y);
	if (cub3d->raycast.sideDist_x)
		free(cub3d->raycast.sideDist_x);
	if (cub3d->raycast.sideDist_y)
		free(cub3d->raycast.sideDist_y);
	if (cub3d->raycast.wall_hit_x)
		free(cub3d->raycast.wall_hit_x);
	if (cub3d->raycast.wall_hit_y)
		free(cub3d->raycast.wall_hit_y);
	if (cub3d->raycast.perp_wall_dist)
		free(cub3d->raycast.perp_wall_dist);
	if (cub3d->raycast.is_horizontal)
		free(cub3d->raycast.is_horizontal);
	if (cub3d->raycast.hit_type)
		free(cub3d->raycast.hit_type);
}
