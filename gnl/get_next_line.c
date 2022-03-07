/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:19:07 by alukongo          #+#    #+#             */
/*   Updated: 2022/01/28 14:42:20 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
here i check if my line exist else i return null.
line 32) this condition is only for don't have a negative value in size_line
line 35) i copy the char from line to 0 until the \n to the str
line 36) i copy the char from line to size_line in line, and i free the old address of line
*/
char	*get_the_line(char **line, int size_line)
{
	char	*str;

	if (!*line || !**line)
	{
		if (*line)
		{
			free(*line);
			*line = (NULL);
		}
		return (NULL);
	}
	if (size_line == -1)
		size_line = ft_strlen(*line);
	str = ft_substr(*line, 0, size_line + 1, 0);
	*line = ft_substr(*line, size_line + 1, ft_strlen(*line), 1);
	return (str);
}

/*
first i check of the fd, BUFFER_SIZE, and read
line 46) i check the number of char before the \n in my line otherwise line = -1 and i read.
in my loop while there isn't \n in line and ret > 0, i joint the buffer in my line and i read again.
finaly if i find a \n or my ret < 0 i exit my loop and i return get_the line.
*/
char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE];
	static char	*line;
	int			size_line;
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	size_line = is_newline(line);
	if (size_line == -1)
		ret = read(fd, buf, BUFFER_SIZE);
	while (size_line == -1 && ret > 0)
	{
		buf[ret] = '\0';
		line = ft_strjoin(line, buf);
		size_line = is_newline(line);
		if (size_line == -1)
			ret = read(fd, buf, BUFFER_SIZE);
	}
	return (get_the_line(&line, size_line));
}
