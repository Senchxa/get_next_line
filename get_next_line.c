/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnoll <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:51:41 by dnoll             #+#    #+#             */
/*   Updated: 2023/06/03 12:13:34 by dnoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_next_position(char *next_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (next_line[i] && next_line[i] != '\n')
	{
		i++;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(next_line) - i + 1));
	if (!str)
	{
		return (NULL);
	}
	i++;
	j = 0;
	while (next_line[i])
	{
		str[j] = next_line[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(next_line);
	return (str);
}

char	*ft_copy_line(char *next_line)
{
	int	i;
	char	*str;

	i = 0;
	if (!next_line[i])
	{
		return (NULL);
	}
	while (next_line[i] && next_line[i] != '\n')
	{
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (next_line[i] && next_line[i] != '\n')
	{
		str[i] = next_line[i];
		i++;
	}
	if (next_line[i] == '\n')
	{
		str[i] = next_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_read(int fd, char *next_line)
{
	char	*buffer;
	int		read_line;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		return (NULL);
	}
	read_line = 1;
	while (!ft_strchr(next_line, '\n') && read_line != 0)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line == -1)
		{
			return (NULL);
		}
		buffer[read_line] = '\0';
		next_line = ft_strjoin(next_line, buffer);
	}
	free (buffer);
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	next_line = ft_read(fd, next_line);
	if(!next_line)
	{
		return (NULL);
	}
	line = ft_copy_line(next_line);
	next_line = ft_next_position(next_line);
	return  (line);

}
