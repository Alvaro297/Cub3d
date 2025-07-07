#include "./cub3d.h"

void	check_name(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".cub", 4) != 0)
		(printf("Error\nIncorrect extension\n"), exit(1));
}

void	check_rgb(char *str, int rgb[3])
{
	char	**splited;
	char	*trimmed;
	int		i;
	int		j;

	splited = ft_split(str, ',');
	if (!splited || !splited[0] || !splited[1] || !splited[2] || splited[3])
		(printf("Error\nIncorrect RGB format\n"), exit(1));
	i = -1;
	while (++i < 3)
	{
		trimmed = ft_strtrim(splited[i], " \t\n");
		if (!trimmed || *trimmed == '\0')
			(printf("Error\nMissing RGB\n"), exit(1));
		j = -1;
		while (trimmed[++j])
			if (!ft_isdigit(trimmed[j]))
				(printf("Error\nRGB is not numeric\n"), exit(1));
		rgb[i] = ft_atoi(trimmed);
		if (rgb[i] < 0 || rgb[i] > 255)
			(printf("Error\nRGB value out of range\n"), exit(1));
		free(trimmed);
	}
	i = -1;
	ft_freedom(splited);
}

static void	handle_map_line(char *line, t_cub3d *cub3d,
	char **map_lines)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		cub3d->map.tex_no = ft_strdup(ft_strtrim(line + 3, " \n"));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		cub3d->map.tex_so = ft_strdup(ft_strtrim(line + 3, " \n"));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		cub3d->map.tex_we = ft_strdup(ft_strtrim(line + 3, " \n"));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		cub3d->map.tex_ea = ft_strdup(ft_strtrim(line + 3, " \n"));
	else if (ft_strncmp(line, "C ", 2) == 0)
		check_rgb(line + 2, cub3d->map.rgb_ceiling);
	else if (ft_strncmp(line, "F ", 2) == 0)
		check_rgb(line + 2, cub3d->map.rgb_floor);
	else if (is_line(line))
		map_lines[cub3d->map.map_index++] = ft_strdup(line);
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
		handle_map_line(line, cub3d, map_lines);
		free(line);
	}
	map_lines[cub3d->map.map_index] = NULL;
	cub3d->map.matriz = map_lines;
	get_next_line(fd, 1);
	close(fd);
}
