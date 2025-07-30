#include "../cub3d_bonus.h"

unsigned int	get_texture_color_door(t_door *texture, double x, double y)
{
	int				pixel_index;
	unsigned int	*buffer;
	unsigned int	color;

	if (!texture || !texture->data)
		return (0x00FF00);
	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0x00FF00);
	pixel_index = y * (texture->line_length / 4) + x;
	buffer = (unsigned int *)texture->data;
	color = buffer[pixel_index];
	return (color);
}
