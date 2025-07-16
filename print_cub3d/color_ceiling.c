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
