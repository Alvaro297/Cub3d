#include "./cub3d.h"

static int	error_rgb(char **splited, char *trimmed, char *msg)
{
	if (trimmed)
		free(trimmed);
	if (splited)
		ft_freedom(splited);
	printf("Error\n%s\n", msg);
	return (1);
}

int	check_rgb(char *str, int rgb[3])
{
	char	**splited;
	char	*trimmed;
	int		i;
	int		j;

	splited = ft_split(str, ',');
	if (!splited || !splited[0] || !splited[1] || !splited[2] || splited[3])
		return (error_rgb(splited, NULL, "Incorrect RGB format"));
	i = -1;
	while (++i < 3)
	{
		trimmed = ft_strtrim(splited[i], " \t\n");
		if (!trimmed || *trimmed == '\0')
			return (error_rgb(splited, trimmed, "Missing RGB"));
		j = -1;
		while (trimmed[++j])
			if (!ft_isdigit(trimmed[j]))
				return (error_rgb(splited, trimmed, "RGB is not numeric"));
		rgb[i] = ft_atoi(trimmed);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (error_rgb(splited, trimmed, "RGB values is out of range"));
		free(trimmed);
	}
	ft_freedom(splited);
	return (0);
}

static void	set_texture(t_cub3d *cub3d, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
	{
		cub3d->map.tex_no = ft_strtrim(line + 3, " \n");
		cub3d->map.count_textures++;
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		cub3d->map.tex_so = ft_strtrim(line + 3, " \n");
		cub3d->map.count_textures++;
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		cub3d->map.tex_we = ft_strtrim(line + 3, " \n");
		cub3d->map.count_textures++;
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		cub3d->map.tex_ea = ft_strtrim(line + 3, " \n");
		cub3d->map.count_textures++;
	}
}

static int	handle_map_line(char *line, t_cub3d *cub3d,
	char **map_lines)
{
	if (!ft_strncmp(line, "NO ", 3))
		set_texture(cub3d, line);
	else if (!ft_strncmp(line, "SO ", 3))
		set_texture(cub3d, line);
	else if (!ft_strncmp(line, "WE ", 3))
		set_texture(cub3d, line);
	else if (!ft_strncmp(line, "EA ", 3))
		set_texture(cub3d, line);
	else if (!ft_strncmp(line, "C ", 2)
		&& check_rgb(line + 2, cub3d->map.rgb_ceiling))
		return (ft_free_map(map_lines, cub3d), 1);
	else if (!ft_strncmp(line, "F ", 2)
		&& check_rgb(line + 2, cub3d->map.rgb_floor))
		return (ft_free_map(map_lines, cub3d), 1);
	else if (is_line(line))
		map_lines[cub3d->map.map_index++] = ft_strdup(line);
	return (0);
}

void	read_map(char *filename, t_cub3d *cub3d)
{
	int		fd;
	char	**map_lines;
	char	*line;
	int		n_lines;

	n_lines = coun_lines(filename);
	map_lines = malloc(sizeof(char *) * (n_lines + 1));
	if (!map_lines)
		(printf("Error\nMalloc of map failed\n"), exit(1));
	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		if (handle_map_line(line, cub3d, map_lines) == 1)
			(free(line), get_next_line(fd, 1), free_cub3d(cub3d), exit(1));
		if (cub3d->map.count_textures != 4)
			(free(line), get_next_line(fd, 1), free_cub3d(cub3d), printf("Error\n Incorrect nº of textures\n") ,exit(1));
		free(line);
	}
	map_lines[cub3d->map.map_index] = NULL;
	cub3d->map.matriz = map_lines;
	get_next_line(fd, 1);
	close(fd);
}
