# include "../cub3d_bonus.h"

int	calculate_texture_x_coord(t_cub3d *cub3d, t_texture *tex)
{
	double	hit_coord_on_wall;
	double	dec_x;
	int		texture_x_coord;

	if (cub3d->raycast.is_horizontal)
		hit_coord_on_wall = cub3d->raycast.wall_hit_y;
	else
		hit_coord_on_wall = cub3d->raycast.wall_hit_x;
	dec_x = hit_coord_on_wall - floor(hit_coord_on_wall);
	if (dec_x < 0)
		dec_x += 1.0;
	texture_x_coord = (int)(dec_x * tex->width);
	if ((cub3d->raycast.is_horizontal && cub3d->raycast.raydir_x < 0) ||
		(!cub3d->raycast.is_horizontal && cub3d->raycast.raydir_y > 0))
		texture_x_coord = tex->width - texture_x_coord - 1;
	return (texture_x_coord);
}

int	calculate_texture_y_coord(int y, int draw_start, int draw_end, t_texture *tex)
{
	int	texture_y_coord;

	texture_y_coord = ((y - draw_start) * tex->height) / (draw_end - draw_start);
	return (texture_y_coord);
}

unsigned int	print_door(t_cub3d *cub3d, int direction, int y, int draw_start, int draw_end)
{
	int			texture_x_coord;
	int			texture_y_coord;
	t_texture	*tex;

	tex = &cub3d->image.doors;
	texture_x_coord = calculate_texture_x_coord_door(cub3d, tex);
	texture_y_coord = calculate_texture_y_coord_door(y, draw_start, draw_end, tex);
	return (get_texture_color_door(tex, texture_x_coord, texture_y_coord));
}

unsigned int	print_textures(t_cub3d *cub3d, int direction, int y, int draw_start, int draw_end)
{
	int			texture_x_coord;
	int			texture_y_coord;
	t_texture	*tex;

	tex = NULL;
	if (direction == 0)
		tex = &cub3d->image.tex_north;
	else if (direction == 1)
		tex = &cub3d->image.tex_south;
	else if (direction == 2)
		tex = &cub3d->image.tex_west[cub3d->image.animation_frame_west];
	else if (direction == 3)
		tex = &cub3d->image.tex_east[cub3d->image.animation_frame];
	else
		return (print_door(cub3d, direction, y, draw_start, draw_end));
	texture_x_coord = calculate_texture_x_coord(cub3d, tex);
	texture_y_coord = calculate_texture_y_coord(y, draw_start, draw_end, tex);
	return (get_texture_color(tex, texture_x_coord, texture_y_coord));
}
/*
unsigned int	print_textures(t_cub3d *cub3d, int direction, int y, int draw_start, int draw_end)
{
	double	wall_x;
	double	dec_x;
	int		texture;
	int		texture_y;
	t_texture *tex;
	static int debug_count = 0;

	if (direction == 0)
		tex = &cub3d->image.tex_north;
	else if (direction == 1)
		tex = &cub3d->image.tex_south;
	else if (direction == 2)
		tex = &cub3d->image.tex_west;
	else if (direction == 3)
		tex = &cub3d->image.tex_east;
	else
		return (0x00FF00);
	if (cub3d->raycast.is_horizontal)
		wall_x = cub3d->raycast.wall_hit_x;
	else
		wall_x = cub3d->raycast.wall_hit_y;
	dec_x = wall_x - floor(wall_x);
	texture = dec_x * tex->width;
	if ((direction == 0 && cub3d->raycast.is_horizontal && cub3d->raycast.raydir_y < 0) ||
		(direction == 1 && cub3d->raycast.is_horizontal && cub3d->raycast.raydir_y > 0) ||
		(direction == 2 && !cub3d->raycast.is_horizontal && cub3d->raycast.raydir_x < 0) ||
		(direction == 3 && !cub3d->raycast.is_horizontal && cub3d->raycast.raydir_x > 0))
		texture = tex->width - texture - 1;
	texture_y = ((y - draw_start) * tex->height) / (draw_end - draw_start);
	
	if (debug_count < 10)
	{
		printf("TEXTURE CALC #%d: dir=%d wall_x=%.3f dec_x=%.3f texture=%d texture_y=%d (tex_size=%dx%d)\n", 
			debug_count, direction, wall_x, dec_x, texture, texture_y, tex->width, tex->height);
		debug_count++;
	}
	
	return (get_texture_color(tex, texture, texture_y));
}*/
