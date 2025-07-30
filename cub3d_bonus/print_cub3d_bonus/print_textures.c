# include "../cub3d_bonus.h"

static t_texture	*texture_decider(t_cub3d *cub3d, int direction)
{
	t_texture	*tex;

	tex = NULL;
	if (direction == 4)
		tex = &cub3d->image.doors;
	else if (direction == 0)
		tex = &cub3d->image.tex_north;
	else if (direction == 1)
		tex = &cub3d->image.tex_south;
	else if (direction == 2)
		tex = &cub3d->image.tex_west[cub3d->image.animation_frame_west];
	else if (direction == 3)
		tex = &cub3d->image.tex_east[cub3d->image.animation_frame];
	return (tex);
}

static int	calc_tex_y(t_texture *tex, int draw_end, int draw_start, int y)
{
	int		total;
	double	wall_pos;

	wall_pos = 0.0;
	if (draw_end != draw_start)
	{
		wall_pos = (double)(y - draw_start) / (double)(draw_end - draw_start);
		if (wall_pos < 0.0)
			wall_pos = 0.0;
		if (wall_pos > 1.0)
			wall_pos = 1.0;
		total = (int)(wall_pos * (double)tex->height);
	}
	else
		total = 0;
	return(total);
}

static void		print_texture_help(t_texture *tex, int *tex_x, int *tex_y)
{
	if (*tex_x < 0)
		*tex_x = 0;
	if (*tex_x >= tex->width)
		*tex_x = tex->width - 1;
	if (*tex_y < 0)
		*tex_y = 0;
	if (*tex_y >= tex->height)
		*tex_y = tex->height - 1;
}

unsigned int	print_textures(t_cub3d *cub3d, int direction, int y, int draw_start, int draw_end)
{
	double		wall_x;
	int			tex_x;
	int			tex_y;
	t_texture	*tex;

	tex = texture_decider(cub3d, direction);
	if (cub3d->raycast.is_horizontal)
		wall_x = cub3d->raycast.wall_hit_x;
	else
		wall_x = cub3d->raycast.wall_hit_y;
	wall_x = wall_x - floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if ((!cub3d->raycast.is_horizontal && cub3d->raycast.raydir_x > 0) ||
		(cub3d->raycast.is_horizontal && cub3d->raycast.raydir_y < 0))
		tex_x = tex->width - tex_x - 1;
	tex_y = calc_tex_y(tex, draw_end, draw_start, y);
	print_texture_help(tex, &tex_x, &tex_y);
	return (get_texture_color(tex, tex_x, tex_y));
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
