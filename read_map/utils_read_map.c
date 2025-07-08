#include "./cub3d.h"

int	is_line(char *line)
{
	while (*line && *line != '\n')
	{
		if (*line != ' ' && *line != '0' && *line != '1'
			&& *line != 'N' && *line != 'S' && *line != 'E' && *line != 'W')
			return (0);
		line++;
	}
	return (1);
}

int	coun_lines(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		(printf("Error\nCould not open file\n"), exit(1));
	}
	count = 0;
	line = get_next_line(fd, 0);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd, 0);
	}
	close(fd);
	return (count);
}

void	check_name(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".cub", 4) != 0)
		(printf("Error\nIncorrect extension\n"), exit(1));
}
