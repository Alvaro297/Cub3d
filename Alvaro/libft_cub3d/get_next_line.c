/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:14:25 by alvamart          #+#    #+#             */
/*   Updated: 2025/07/08 00:51:08 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static char	*ft_next_line(char *line)
{
	size_t	i;
	size_t	n;
	char	*tline;

	i = 0;
	n = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	tline = ft_calloc(sizeof(char), (ft_strlen(line) - i + 1));
	if (!tline)
		return (NULL);
	i++;
	while (line[i] != '\0')
		tline[n++] = line[i++];
	tline[n] = '\0';
	free(line);
	return (tline);
}

static char	*full_line(char *tline)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!tline[j])
		return (NULL);
	while (tline[j] != '\n' && tline[j] != '\0')
		j++;
	line = ft_calloc(sizeof(char), j + 2);
	if (!line)
		return (NULL);
	while (tline[i] != '\n' && tline[i] != '\0')
	{
		line[i] = tline[i];
		i++;
	}
	if (tline[i] && tline[i] == '\n')
		line[i] = '\n';
	line[++i] = '\0';
	return (line);
}

static char	*ft_get_line(int fd, char *tline)
{
	char	*line;
	size_t	bytesread;

	bytesread = 1;
	line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (bytesread > 0 && !ft_strchr(tline, '\n'))
	{
		bytesread = read(fd, line, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			free(tline);
			free(line);
			return (NULL);
		}
		line[bytesread] = '\0';
		if (!tline)
			tline = ft_strdup(line);
		else
			tline = ft_strjoin_free(tline, line);
	}
	free(line);
	return (tline);
}

char	*get_next_line(int fd)
{
	static char	*tline = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tline = ft_get_line(fd, tline);
	if (!tline)
		return (NULL);
	line = full_line(tline);
	tline = ft_next_line(tline);
	if (line && *line == '\0')
	{
		free(line);
		free(tline);
		line = NULL;
		tline = NULL;
	}
	return (line);
} */
char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_cleanline(char *str)
{
	char			*newstring;
	char			*character;
	unsigned int	len;

	character = ft_strchr_gnl(str, '\n');
	if (!character)
	{
		newstring = NULL;
		return (ft_free(&str));
	}
	else
		len = (unsigned int)(character - str) + 1;
	if (!str[len])
		return (ft_free(&str));
	newstring = ft_substr(str, len, ft_strlen(str) - len);
	if (!newstring)
		return (NULL);
	ft_free(&str);
	return (newstring);
}

char	*ft_get_line(char *str)
{
	char			*line;
	char			*character;
	size_t			len;

	if (!str)
		return (NULL);
	character = ft_strchr_gnl(str, '\n');
	len = (size_t)(character - str) + 1;
	line = ft_substr(str, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_reading(int fd, char *str)
{
	char		*buffer;
	ssize_t		bytes_read;

	if (BUFFER_SIZE < 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&str));
	bytes_read = 1;
	buffer[0] = '\0';
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			str = ft_strjoin_gnl(str, buffer);
		}
	}
	free(buffer);
	if (bytes_read == -1)
		return (ft_free(&str));
	return (str);
}

char	*get_next_line(int fd, int mode)
{
	static char	*str;
	char		*line;

	if (mode == 1)
	{
		ft_free(&str);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((str && !ft_strchr_gnl(str, '\n')) || !str)
		str = ft_reading(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	if (!line)
		return (ft_free(&str));
	str = ft_cleanline(str);
	return (line);
}

char	*ft_strchr_gnl(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*result;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	result = malloc(lens1 + lens2 + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, lens1);
	ft_memcpy(result + lens1, s2, lens2 + 1);
	free(s1);
	return (result);
}

void	*ft_memcpy_gnl(void *dst, const void *src, size_t n)
{
	void		*ret;
	char		*p_dst;
	const char	*p_src;

	if (!dst && !src)
		return (NULL);
	ret = dst;
	p_dst = (char *)dst;
	p_src = (const char *)src;
	while (n--)
		*p_dst++ = *p_src++;
	return (ret);
}

/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	argc = 1;
	fd = open(argv[argc], O_RDONLY);
	if (fd == -1)
    	perror("Error opening file");
	while ((i <= 6))
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (!str)
			break;
		free(str);
		i++;
	}
	return (0);
}*/
