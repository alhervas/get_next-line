/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhervas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:41:12 by alhervas          #+#    #+#             */
/*   Updated: 2023/02/22 17:41:15 by alhervas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int		a;
	char	aux;

	aux = c;
	a = 0;
	while ((char)str[a] != '\0')
	{
		if (((char *)str)[a] == aux)
		{
			return ((char *)&str[a]);
		}
		a++;
	}
	if (aux == '\0')
		return ((char *)&str[a]);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*dest;

	i = nmemb * size;
	dest = malloc(i);
	if (!(dest))
		return (0);
	ft_bzero(dest, i);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!s)
		return (0);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s[i] = s2[j];
		j++;
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	ft_bzero(void *b, size_t len)
{
	size_t	i;

	i = 0;
	while (len > i)
	{
		((char *)b)[i] = 0;
		i++;
	}
}