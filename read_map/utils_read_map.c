#include "./cub3d.h"

int	is_line(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '0' && *line != '1'
			&& *line != 'N' && *line != 'S' && *line != 'E' && *line != 'W'
			&& *line != '\n')
			return (0);
		line++;
	}
	return (1);
}

int	coun_lines(char *filename)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		(printf("Error\nCould'nt open map\n"), exit(1));
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || line == (void *)0)
			break ;
		if (is_line(line))
			i++;
		free(line);
	}
	close(fd);
	return (i);
}
