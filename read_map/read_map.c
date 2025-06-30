#include "./cub3d.h"

void	check_name(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (!ft_strcmp(filename, ".cub"))
		(printf("Error\nIncorrect extension\n"), exit(1));
}

void	check_rgb(char *rgb)
{
	
}

void	read_map(char *filename, t_cub3d *cub3d)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		(printf("Error\nCould'nt open map\n"), exit(1));
	while (1)
	{
		line = get_next_line(fd);
		if (!line || line == (void *)0)
			break ;
		if (ft_strncmp(line, "NO ", 3) == 0)
			cub3d->map.tex_no = ft_strdup(ft_strtrim(line + 3, " \n"));
		else if (ft_strncmp(line, "SO ", 3) == 0)
			cub3d->map.tex_so = ft_strdup(ft_strtrim(line + 3, " \n"));
		else if (ft_strncmp(line, "WE ", 3) == 0)
			cub3d->map.tex_we = ft_strdup(ft_strtrim(line + 3, " \n"));
		else if (ft_strncmp(line, "EA ", 3) == 0)
			cub3d->map.tex_ea = ft_strdup(ft_strtrim(line + 3, " \n"));
		else if (ft_strncmp(line, "F ", 3) == 0)
			check_rgb(line);
		/* else if (ft_strncmp(line, "C ", 3) == 0)
			check_rgb(line); */
		printf("%s", line);
	}
}
