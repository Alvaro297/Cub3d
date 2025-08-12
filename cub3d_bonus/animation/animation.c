/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 23:16:11 by alvamart          #+#    #+#             */
/*   Updated: 2025-08-10 23:16:11 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static bool	update_animation_frames(t_cub3d *cub3d)
{
	static int	frame_x = 0;
	static int	frame_y = 5;
	bool		re_casting;

	re_casting = false;
	frame_x++;
	frame_y++;
	if (frame_x % 10 == 0)
	{
		re_casting = true;
		cub3d->image.animation_frame++;
		if (cub3d->image.animation_frame >= TOTAL_ANIMATIONS)
			cub3d->image.animation_frame = 0;
	}
	if (frame_y % 10 == 0)
	{
		re_casting = true;
		cub3d->image.animation_frame_west++;
		if (cub3d->image.animation_frame_west >= TOTAL_ANIMATIONS)
			cub3d->image.animation_frame_west = 0;
	}
	return (re_casting);
}

char	*extract_until_textures(const char *path)
{
	char	*textures_pos;
	char	*result;
	int		len;

	if (!path)
		return (NULL);
	textures_pos = ft_strnstr(path, "textures/", ft_strlen(path));
	if (!textures_pos)
	{
		printf("Error: 'textures/' not found in path\n");
		return (NULL);
	}
	len = textures_pos - path + 9;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, (char *)path, len + 1);
	return (result);
}

int	file_path_animation_help(char **full_path)
{
	int		fd;
	char	buf;

	printf("Trying to open: %s\n", *full_path);
	fd = open((const char *)*full_path, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nCan not open texture file: %s\n", *full_path),
			free(*full_path), 1);
	if (read(fd, &buf, 1) <= 0)
		return (close(fd), printf("Error\nTexture file\n"),
			free(*full_path), 1);
	close(fd);
	free(*full_path);
	return (0);
}

int	file_path_animation(char *path_animation, int i, int is_east)
{
	char	*nmbr;
	char	*full_path;

	nmbr = ft_itoa(i);
	nmbr = ft_strjoin_free(nmbr, ".xpm");
	if (is_east)
		full_path = ft_strjoin_free(ft_strdup(path_animation),
				"animation/animation_east_");
	else
		full_path = ft_strjoin_free(ft_strdup(path_animation),
				"animation/animation_west_");
	if (!full_path)
		return (free(nmbr), 1);
	full_path = ft_strjoin_free(full_path, nmbr);
	free(nmbr);
	return (file_path_animation_help(&full_path));
}

void	ft_animation(t_cub3d *cub3d)
{
	if (update_animation_frames(cub3d))
	{
		raycast(cub3d);
		draw_minimap(cub3d);
	}
}
