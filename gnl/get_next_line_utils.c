/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:19:00 by alukongo          #+#    #+#             */
/*   Updated: 2022/01/22 18:16:40 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	is_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	int		i;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = -1;
	str = malloc(sizeof(char) * len1 + len2 + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2 && s2[++i])
		str[len1 + i] = s2[i];
	if (i < 0)
		i = 0;
	str[len1 + i] = '\0';
	if (s1)
		free (s1);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len, int free_s)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			str[i] = s[start + i];
			i++;
		}
	}
	str[i] = '\0';
	if (free_s && s)
		free(s);
	return (str);
}
