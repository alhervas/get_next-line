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

#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] && str[n] != '\0')
		n++;
	return (n);
}

void	*ft_calloc(int size, int num)
{
	char	*array;
	int		pos;

	pos = 0;
	array = malloc(size * num);
	if (!array)
		return (NULL);
	if (array && size > 0 && num > 0)
	{
		while (pos < (size * num))
		{
			array[pos] = 0;
			pos++;
		}
		return ((void *) array);
	}
	else
		return ((void *) array);
}

char	*ft_strchr(const char *array, int character)
{
	while (array && *array)
	{
		if (*array == (unsigned char)character)
			return ((char *)array);
		array++;
	}
	if ((unsigned char)character == '\0')
		return ((char *)array);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	count;

	count = 0;
	if ((len + start) > ft_strlen(s) || len > ft_strlen(s))
		len = (ft_strlen(s) - start);
	if (start >= ft_strlen(s))
		len = 0;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (s[count] && len)
	{
		str[count] = s[start];
		start++;
		count++;
		len--;
	}
	str[count] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		pos_s;
	int		str_pos;
	char	*str;

	pos_s = 0;
	str_pos = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[pos_s] != '\0')
		str[str_pos++] = s1[pos_s++];
	pos_s = 0;
	while (s2[pos_s] != '\0')
		str[str_pos++] = s2[pos_s++];
	str[str_pos] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}
