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
	static int		error_count = 0;
	static int		debug_count = 0;
	unsigned int	color;

	if (!texture || !texture->data)
	{
		if (error_count < 5)
			printf("ERROR: Textura o data es NULL\n");
		error_count++;
		return (0xFF0000);
	}
	
	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
	{
		if (error_count < 5)
			printf("ERROR: Coordenadas fuera de rango - x:%d y:%d (max: %dx%d)\n", 
				x, y, texture->width, texture->height);
		error_count++;
		return (0xFF0000);
	}
	pixel_index = y * (texture->line_length / 4) + x;
	buffer = (unsigned int *)texture->data;
	color = buffer[pixel_index];
	
	if (debug_count < 10)
	{
		printf("TEXTURE COLOR #%d: x=%d y=%d pixel_index=%d color=0x%08X\n", 
			debug_count, x, y, pixel_index, color);
		debug_count++;
	}
	
	return (color);
}
