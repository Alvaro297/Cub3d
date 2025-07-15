#include "./cub3d.h"

int	check_texture_file(const char *path)
{
	int		fd;
	char	buf;

	printf("Trying to open: %s\n", path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nCan not open texture file: %s\n", path), 1);
	if (read(fd, &buf, 1) <= 0)
		return (close(fd), printf("Error\nTexture file\n"), 1);
	close(fd);
	return (0);
}

int	check_texture_name(const char *path)
{
	size_t	len;

    len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (printf("Error\nIn texture extension\n"), 1);
	return (0);
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
		|| check_texture_file(cub3d->map.tex_so)
		|| check_texture_file(cub3d->map.tex_so)
		|| check_texture_file(cub3d->map.tex_we)
		|| check_texture_file(cub3d->map.tex_ea))
		(free_cub3d(cub3d), exit(1));
}
