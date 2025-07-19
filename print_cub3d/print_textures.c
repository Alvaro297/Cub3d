# include "../cub3d.h"

static unsigned int	print_north(t_cub3d *cub3d, int y, int draw_end)
{
	double	wall_x;
	double	dec_x;
	int		texture;
	int		texture_y;
	int		draw_start;

	draw_start = (SCREEN_HEIGHT - (draw_end - y)) / 2;
	if (cub3d->raycast.is_horizontal)
		wall_x = cub3d->raycast.wall_hit_x;
	else
		wall_x = cub3d->raycast.wall_hit_y;
	dec_x = wall_x - floor(wall_x);
	texture = dec_x * cub3d->image.tex_north.width;
	if (cub3d->raycast.is_horizontal && cub3d->raycast.raydir_y < 0)
		texture = cub3d->image.tex_north.width - texture - 1;
	texture_y = ((y - draw_start) * cub3d->image.tex_north.height) / (draw_end - draw_start);
	return (get_texture_color(&cub3d->image.tex_north, texture, texture_y));
}

static unsigned int	print_south(t_cub3d *cub3d, int y, int draw_end)
{
	double	wall_x;
	double	dec_x;
	int		texture;
	int		texture_y;
	int		draw_start;

	draw_start = (SCREEN_HEIGHT - (draw_end - y)) / 2;
	if (cub3d->raycast.is_horizontal)
		wall_x = cub3d->raycast.wall_hit_x;
	else
		wall_x = cub3d->raycast.wall_hit_y;
	dec_x = wall_x - floor(wall_x);
	texture = dec_x * cub3d->image.tex_south.width;
	if (cub3d->raycast.is_horizontal && cub3d->raycast.raydir_y > 0)
		texture = cub3d->image.tex_south.width - texture - 1;
	texture_y = ((y - draw_start) * cub3d->image.tex_south.height) / (draw_end - draw_start);
	return (get_texture_color(&cub3d->image.tex_south, texture, texture_y));
}

static unsigned int	print_west(t_cub3d *cub3d, int y, int draw_end)
{
	double	wall_x;
	double	dec_x;
	int		texture;
	int		texture_y;
	int		draw_start;

	draw_start = (SCREEN_HEIGHT - (draw_end - y)) / 2;
	if (cub3d->raycast.is_horizontal)
		wall_x = cub3d->raycast.wall_hit_x;
	else
		wall_x = cub3d->raycast.wall_hit_y;
	dec_x = wall_x - floor(wall_x);
	texture = dec_x * cub3d->image.tex_west.width;
	if (!cub3d->raycast.is_horizontal && cub3d->raycast.raydir_x < 0)
		texture = cub3d->image.tex_west.width - texture - 1;
	texture_y = ((y - draw_start) * cub3d->image.tex_west.height) / (draw_end - draw_start);
	return (get_texture_color(&cub3d->image.tex_west, texture, texture_y));
}

static unsigned int	print_east(t_cub3d *cub3d, int y, int draw_end)
{
	double	wall_x;
	double	dec_x;
	int		texture;
	int		texture_y;
	int		draw_start;

	draw_start = (SCREEN_HEIGHT - (draw_end - y)) / 2;
	if (cub3d->raycast.is_horizontal)
		wall_x = cub3d->raycast.wall_hit_x;
	else
		wall_x = cub3d->raycast.wall_hit_y;
	dec_x = wall_x - floor(wall_x);
	texture = dec_x * cub3d->image.tex_east.width;
	if (!cub3d->raycast.is_horizontal && cub3d->raycast.raydir_x > 0)
		texture = cub3d->image.tex_east.width - texture - 1;
	texture_y = ((y - draw_start) * cub3d->image.tex_east.height) / (draw_end - draw_start);
	return (get_texture_color(&cub3d->image.tex_east, texture, texture_y));
}


int	print_textures(t_cub3d *cub3d, int direction, int y, int draw_end)
{	
	if (direction == 0)
		return (print_north(cub3d, y, draw_end));
	else if (direction == 1)
		return (print_south(cub3d, y, draw_end));
	else if (direction == 2)
		return (print_west(cub3d, y, draw_end));
	else if (direction == 3)
		return (print_east(cub3d, y, draw_end));
	else
		return (printf("Error en el tipo"), 1);
}