/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-07 18:54:29 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-07 18:54:29 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	free_texture_paths(t_cub3d *cub3d)
{
	if (cub3d->map.tex_no)
		free(cub3d->map.tex_no);
	if (cub3d->map.tex_so)
		free(cub3d->map.tex_so);
	if (cub3d->map.tex_we)
		free(cub3d->map.tex_we);
	if (cub3d->map.tex_ea)
		free(cub3d->map.tex_ea);
}

static void	free_map_matriz(t_cub3d *cub3d)
{
	int	i;

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
}

static void	free_mlx_images(t_cub3d *cub3d)
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

void	free_cub3d(t_cub3d *cub3d)
{
	free_texture_paths(cub3d);
	free_map_matriz(cub3d);
	free_norm_matriz(cub3d);
	if (cub3d->mlx_ptr)
		free_mlx_images(cub3d);
}
