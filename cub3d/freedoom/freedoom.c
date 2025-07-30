#include "../cub3d.h"

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
	int	i;

	if (cub3d->map.tex_no)
		free(cub3d->map.tex_no);
	if (cub3d->map.tex_so)
		free(cub3d->map.tex_so);
	if (cub3d->map.tex_we)
		free(cub3d->map.tex_we);
	if (cub3d->map.tex_ea)
		free(cub3d->map.tex_ea);
	if (cub3d->map.matriz)
	{
		i = 0;
		while (cub3d->map.matriz[i])
		{
			free(cub3d->map.matriz[i]);
			i++;
		}
		free(cub3d->map.matriz);
	}
	if (cub3d->mlx_ptr)
	{
		if (cub3d->image.tex_north.img_ptr)
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->image.tex_north.img_ptr);
		if (cub3d->image.tex_south.img_ptr)
			mlx_destroy_image(cub3d->mlx_ptr, cub3d->image.tex_south.img_ptr);
		if (cub3d->image.tex_east.img_ptr)
			mlx_destroy_image(cub3d->mlx_ptr, cub3d->image.tex_east.img_ptr);
		if (cub3d->image.tex_west.img_ptr)
			mlx_destroy_image(cub3d->mlx_ptr, cub3d->image.tex_west.img_ptr);
		if (cub3d->img_ptr)
			mlx_destroy_image(cub3d->mlx_ptr, cub3d->img_ptr);
	}
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
