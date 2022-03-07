/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:03:18 by alukongo          #+#    #+#             */
/*   Updated: 2021/07/19 12:12:28 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
//#include "so_long.h"

char	*ft_find(int c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

int	ft_len_word(char *str, char *charset)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if ((ft_find(str[i], charset) == NULL))
		{
			len++;
			i++;
		}
		else
			break ;
	}
	return (len);
}

char	*ft_strdup(char *src, char *charset)
{
	int		i;
	char	*dest;
	int		len;

	i = 0;
	len = ft_len_word(src, charset);
	dest = malloc(sizeof(*src) * (len + 1));
	if (dest == NULL)
		return (0);
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	nbr_word;

	i = 0;
	nbr_word = 0;
	while (str[i])
	{
		if ((ft_find(str[i], charset) == NULL) && (i == 0))
		{
			nbr_word++;
			i++;
		}
		if ((ft_find(str[i], charset) == NULL)
			&& (ft_find(str[i - 1], charset) != NULL))
			nbr_word++;
		i++;
	}
	return (nbr_word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		nbr_word;

	nbr_word = ft_count_word(str, charset);
	tab = (char **)malloc(sizeof(char *) * (nbr_word + 1));
	if (tab == NULL)
		return (NULL);
	tab[nbr_word] = NULL;
	i = 0;
	while (*str)
	{
		if (ft_find(*str, charset) == NULL)
		{
			tab[i] = ft_strdup(str, charset);
			i++;
			str += ft_len_word(str, charset);
		}
		else
			str++;
	}
	return (tab);
}
