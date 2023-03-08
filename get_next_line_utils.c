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