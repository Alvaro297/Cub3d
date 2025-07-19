# include "../cub3d.h"

unsigned int	print_textures(t_cub3d *cub3d, int direction, int y, int draw_start, int draw_end)
{
	double	wall_x;
	double	dec_x;
	int		texture;
	int		texture_y;
	t_texture *tex;

	if (direction == 0)
		tex = &cub3d->image.tex_north;
	else if (direction == 1)
		tex = &cub3d->image.tex_south;
	else if (direction == 2)
		tex = &cub3d->image.tex_west;
	else if (direction == 3)
		tex = &cub3d->image.tex_east;
	else
		return (0xFF0000);
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
	return (get_texture_color(tex, texture, texture_y));
}
