#include "../cub3d.h"

void	color_floor_ceiling(t_cub3d *cub3d)
{
	int	red;
	int	green;
	int	blue;

	red = 0;
	green = 0;
	blue = 0;
	red = cub3d->map.rgb_ceiling[0] * (256 * 256);
	green = cub3d->map.rgb_ceiling[1] * 256;
	blue = cub3d->map.rgb_ceiling[2];
	cub3d->map.ceiling = red + green + blue;
	red = 0;
	green = 0;
	blue = 0;
	red = cub3d->map.rgb_floor[0] * (256 * 256);
	green = cub3d->map.rgb_floor[1] * 256;
	blue = cub3d->map.rgb_floor[2];
	cub3d->map.floor = red + green + blue;
}

unsigned int	get_texture_color(t_texture *texture, int x, int y)
{
	int				pixel_index;
	unsigned int	*buffer;
	unsigned int	color;

	// Verificaciones de seguridad
	if (!texture || !texture->data)
		return (0xFF00FF); // Magenta para debug
	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0xFF00FF); // Magenta para debug
	
	// Calcular índice del pixel de manera más segura
	pixel_index = y * (texture->line_length / (texture->bits_per_pixel / 8)) + x;
	buffer = (unsigned int *)texture->data;
	color = buffer[pixel_index];
	return (color);
}
