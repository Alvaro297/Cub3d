# include "../cub3d.h"

void	load_images(t_cub3d *cub3d)
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
	cub3d->image.tex_east.img_ptr = mlx_xpm_file_to_image(cub3d->mlx_ptr, cub3d->map.tex_ea,
			&cub3d->image.tex_east.width, &cub3d->image.tex_east.height);
	cub3d->image.tex_east.data = mlx_get_data_addr(cub3d->image.tex_east.img_ptr,
		&cub3d->image.tex_east.bits_per_pixel,
		&cub3d->image.tex_east.line_length, &cub3d->image.tex_east.endian);
	cub3d->image.tex_west.img_ptr = mlx_xpm_file_to_image(cub3d->mlx_ptr, cub3d->map.tex_we,
			&cub3d->image.tex_west.width, &cub3d->image.tex_west.height);
	cub3d->image.tex_west.data = mlx_get_data_addr(cub3d->image.tex_west.img_ptr,
		&cub3d->image.tex_west.bits_per_pixel,
		&cub3d->image.tex_west.line_length, &cub3d->image.tex_west.endian);
}
