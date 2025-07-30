#include "../cub3d_bonus.h"

void	ft_freedom(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			str[i] = NULL;
			i++;
		}
		free(str);
	}
	else
		return ;
}

void	ft_free_map(char **map_lines, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	if (!map_lines)
		return ;
	while (i < cub3d->map.map_index)
	{
		if (map_lines[i])
		{
			free(map_lines[i]);
			map_lines[i++] = NULL;
		}
		else
			i++;
	}
	if (map_lines)
		free(map_lines);
	map_lines = NULL;
}

void	free_cub3d(t_cub3d *cub3d)
{
	if (cub3d->map.tex_no)
		free(cub3d->map.tex_no);
	if (cub3d->map.tex_so)
		free(cub3d->map.tex_so);
	if (cub3d->map.tex_we)
		free(cub3d->map.tex_we);
	if (cub3d->map.tex_ea)
		free(cub3d->map.tex_ea);
	if (cub3d->map.matriz)
		free_matriz(cub3d);
	else
		free_norm_matriz(cub3d);
}

void	free_norm_map(char **map, int upto)
{
	int	i;

	i = 0;
	while (i < upto)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
