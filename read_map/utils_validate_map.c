#include "./cub3d.h"

int	check_texture_file(const char *path)
{
	int		fd;
	char	buf;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCannot open texture file: %s\n", path);
		return (1);
	}
	if (read(fd, &buf, 1) <= 0)
	{
		printf("Error\nTexture file\n");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	check_texture_name(const char *path, const char *expected)
{
	size_t	len;

    len = ft_strlen(path);
	if (!ft_strnstr(path, expected, len))
        return (printf("Error\nIn texture name\n"), 1);
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
        return (printf("Error\nIn texture extension\n"), 1);
	return (0);
}
