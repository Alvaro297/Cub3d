#include "../cub3d_bonus.h"

void	ft_animation(t_cub3d *cub3d)
{
	static int	frame_x = 0;
	static int	frame_y = 5;
	bool		re_casting;

	re_casting = false;
	frame_x++;
	frame_y++;
	if (frame_x % 10 == 0)
	{
		re_casting = true;
		cub3d->image.animation_frame++;
		if (cub3d->image.animation_frame >= TOTAL_ANIMATIONS)
			cub3d->image.animation_frame = 0;
	}
	if (frame_y % 10 == 0)
	{
		re_casting = true;
		cub3d->image.animation_frame_west++;
		if (cub3d->image.animation_frame_west >= TOTAL_ANIMATIONS)
			cub3d->image.animation_frame_west = 0;
	}
	if (re_casting)
	{
		raycast(cub3d);
		draw_minimap(cub3d);
	}
}
