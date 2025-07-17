#include "./cub3d.h"

static void	set_texture(t_cub3d *cub3d, char *line)
{
	char	*ej;

	ej = NULL;
	if (!ft_strncmp(line, "NO ", 3))
	{
		ej = ft_strtrim(line + 3, " \n");
		cub3d->map.tex_no = ft_strjoin("./", ej);
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		ej = ft_strtrim(line + 3, " \n");
		cub3d->map.tex_so = ft_strjoin("./", ej);
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		ej = ft_strtrim(line + 3, " \n");
		cub3d->map.tex_we = ft_strjoin("./", ej);
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		ej = ft_strtrim(line + 3, " \n");
		cub3d->map.tex_ea = ft_strjoin("./", ej);
	}
	free (ej);
	cub3d->map.count_textures++;
}

static int	handle_texture_line(char *line, t_cub3d *cub3d)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3)
		|| !ft_strncmp(line, "EA ", 3))
	{
		set_texture(cub3d, line);
		if (cub3d->map.count_textures == 4)
			cub3d->map.parse += 1;
		return (0);
	}
	return (printf("Error\nExpected texture line\n"), 1);
}

static int	handle_color_line(char *line, t_cub3d *cub3d)
{
	if (!ft_strncmp(line, "F ", 2))
	{
		if (check_rgb(line + 2, cub3d->map.rgb_ceiling))
			return (cub3d->map.count_rgb = 1, 1);
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		if (check_rgb(line + 2, cub3d->map.rgb_floor))
			return (cub3d->map.count_rgb = 2, 1);
		cub3d->map.parse += 1;
	}
	else
		return (printf("Error\nExpected color line\n"), 1);
	return (0);
}

static int	handle_map_content(char *line, t_cub3d *cub3d, char **map_lines)
{
	if (is_line(line))
	{
		map_lines[cub3d->map.map_index++] = ft_strdup(line);
		return (0);
	}
	return (printf("Error\nUnexpected line after map\n"), 1);
}

int	handle_map_line(char *line, t_cub3d *cub3d, char **map_lines)
{
	if (is_blank_line(line))
		return (0);
	if (cub3d->map.parse == 2)
		return (handle_map_content(line, cub3d, map_lines));
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
		return (handle_texture_line(line, cub3d));
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (handle_color_line(line, cub3d));
	if (is_line(line))
	{
		if (cub3d->map.count_textures != 4 || cub3d->map.count_rgb != 2)
			return (printf("Error\nMissing identifiers before map\n"), 1);
		cub3d->map.parse = 2;
		return (handle_map_content(line, cub3d, map_lines));
	}
	return (printf("Error\nUnexpected line\n"), 1);
}
