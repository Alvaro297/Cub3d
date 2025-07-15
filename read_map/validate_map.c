#include "./cub3d.h"

void	validate_map(t_cub3d *cub3d)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (cub3d->map.matriz[y])
	{
		x = 0;
		while (cub3d->map.matriz[y])
		{
			c = cub3d->map.matriz[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				(set_player(cub3d, x, y, c), cub3d->player.player_count++);
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
				|| c == '\0')
			{
				if (!is_closed(cub3d->map.matriz, x, y))
					(printf("Error\nMap is not closed\n"), free_cub3d(cub3d), exit(1));
			}
			x++;
		}
		y++;
	}
	if (cub3d->player.player_count != 1)
		(printf("Error\nincorrect nº of player\n"), free_cub3d(cub3d), exit(1));
}

void	validate_config(t_cub3d *cub3d)
{
	if (!cub3d->map.tex_no || !cub3d->map.tex_so
		|| !cub3d->map.tex_we || !cub3d->map.tex_ea)
		(printf("Error\nMissing textures\n"), free_cub3d(cub3d), exit(1));
	if (cub3d->map.rgb_floor[0] == -1
		|| cub3d->map.rgb_floor[1] == -1
		|| cub3d->map.rgb_floor[2] == -1)
		(printf("Error\nMissing floor color\n"), free_cub3d(cub3d), exit(1));
	if (cub3d->map.rgb_ceiling[0] == -1
		|| cub3d->map.rgb_ceiling[1] == -1
		|| cub3d->map.rgb_ceiling[2] == -1)
		(printf("Error\nMissing ceiling color\n"), free_cub3d(cub3d), exit(1));
}

void	validate_textures(t_cub3d *cub3d)
{
	if (check_texture_file(cub3d->map.tex_no)
		|| check_texture_name(cub3d->map.tex_no, "N")
		|| check_texture_file(cub3d->map.tex_so)
		|| check_texture_name(cub3d->map.tex_so, "S")
		|| check_texture_file(cub3d->map.tex_we)
		|| check_texture_name(cub3d->map.tex_we, "W")
		|| check_texture_file(cub3d->map.tex_ea)
		|| check_texture_name(cub3d->map.tex_ea, "E"))
		(free_cub3d(cub3d), exit(1));
}
