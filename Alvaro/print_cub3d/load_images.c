# include "../cub3d.h"

static void	load_images_animated_help(t_cub3d *cub3d, int i, char *path)
{
	cub3d->image.tex_west[i].img_ptr = mlx_xpm_file_to_image(cub3d->mlx_ptr, path,
			&cub3d->image.tex_west[i].width, &cub3d->image.tex_west[i].height);
	if (cub3d->image.tex_west[i].img_ptr)
		cub3d->image.tex_west[i].data = mlx_get_data_addr(cub3d->image.tex_west[i].img_ptr,
			&cub3d->image.tex_west[i].bits_per_pixel,
			&cub3d->image.tex_west[i].line_length, &cub3d->image.tex_west[i].endian);
}

static void	load_images_animated(t_cub3d *cub3d)
{
	int		i;
	char	*path;
	char	*num;

	i = 1;
	while (i < TOTAL_ANIMATIONS)
	{
		num = ft_itoa(i);
		path = ft_strjoin_free(ft_strjoin("textures/animation/animation_east_", num), ".xpm");
		free(num);
		cub3d->image.tex_east[i].img_ptr = mlx_xpm_file_to_image(cub3d->mlx_ptr, path,
			&cub3d->image.tex_east[i].width, &cub3d->image.tex_east[i].height);
		if (cub3d->image.tex_east[i].img_ptr)
			cub3d->image.tex_east[i].data = mlx_get_data_addr(cub3d->image.tex_east[i].img_ptr,
				&cub3d->image.tex_east[i].bits_per_pixel,
				&cub3d->image.tex_east[i].line_length, &cub3d->image.tex_east[i].endian);
		free(path);
		num = ft_itoa(i);
		path = ft_strjoin_free(ft_strjoin("textures/animation/animation_west_", num), ".xpm");
		free(num);
		load_images_animated_help(cub3d, i, path);
		free(path);
		i++;
	}
}

void	load_images(t_cub3d *cub3d, bool is_bonus)
{
	cub3d->image.tex_north.img_ptr = mlx_xpm_file_to_image(cub3d->mlx_ptr, cub3d->map.tex_no,
			&cub3d->image.tex_north.width, &cub3d->image.tex_north.height);
	cub3d->image.tex_north.data = mlx_get_data_addr(cub3d->image.tex_north.img_ptr,
		&cub3d->image.tex_north.bits_per_pixel,
		&cub3d->image.tex_north.line_length, &cub3d->image.tex_north.endian);
	
	cub3d->image.tex_south.img_ptr = mlx_xpm_file_to_image(cub3d->mlx_ptr, cub3d->map.tex_so,
			&cub3d->image.tex_south.width, &cub3d->image.tex_south.height);
	cub3d->image.tex_south.data = mlx_get_data_addr(cub3d->image.tex_south.img_ptr,
		&cub3d->image.tex_south.bits_per_pixel,
		&cub3d->image.tex_south.line_length, &cub3d->image.tex_south.endian);
	
	cub3d->image.tex_east[0].img_ptr = mlx_xpm_file_to_image(cub3d->mlx_ptr, cub3d->map.tex_ea,
			&cub3d->image.tex_east[0].width, &cub3d->image.tex_east[0].height);
	cub3d->image.tex_east[0].data = mlx_get_data_addr(cub3d->image.tex_east[0].img_ptr,
		&cub3d->image.tex_east[0].bits_per_pixel,
		&cub3d->image.tex_east[0].line_length, &cub3d->image.tex_east[0].endian);
	
	cub3d->image.tex_west[0].img_ptr = mlx_xpm_file_to_image(cub3d->mlx_ptr, cub3d->map.tex_we,
			&cub3d->image.tex_west[0].width, &cub3d->image.tex_west[0].height);
	cub3d->image.tex_west[0].data = mlx_get_data_addr(cub3d->image.tex_west[0].img_ptr,
		&cub3d->image.tex_west[0].bits_per_pixel,
		&cub3d->image.tex_west[0].line_length, &cub3d->image.tex_west[0].endian);
	if (is_bonus)
		load_images_animated(cub3d);
}
