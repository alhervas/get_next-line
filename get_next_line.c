/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhervas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:40:53 by alhervas          #+#    #+#             */
/*   Updated: 2023/02/22 17:40:55 by alhervas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_left(char *str)
{
	int		pos;
	char	*array;

	pos = 0;
	while (str[pos] != '\n' && str[pos] != '\0')
		pos++;
	if (str[pos] == '\n')
		pos++;
	array = NULL;
	if (pos)
		array = ft_substr(str, 0, pos);
	return (array);
}

char	*get_rest(char *str)
{
	int		pos;
	int		r_pos;
	int		count;
	char	*array;

	pos = 0;
	r_pos = 0;
	count = 0;
	if (!(ft_strchr(str, '\n')))
		return (free(str), NULL);
	while (str[pos] != '\n')
		pos++;
	pos++;
	r_pos = pos;
	while (str[pos++] != '\0')
		count++;
	array = ft_substr(str, r_pos, count);
	free(str);
	return (array);
}

char	*free_all(char *str_return, char *first)
{
	(void)first;
	free (str_return);
	return (NULL);
}

static char	*complete_array(int fd, char *first)
{
	char	aux[BUFFER_SIZE + 1];
	char	*str_return;
	int		state;

	str_return = ft_calloc(BUFFER_SIZE, 1);
	if (first)
	{
		free(str_return);
		str_return = ft_substr(first, 0, ft_strlen(first));
		free(first);
		first = NULL;
	}
	state = 1;
	while (!ft_strchr(str_return, '\n') && state)
	{
		state = read(fd, aux, BUFFER_SIZE);
		if (state > 0)
		{
			aux[state] = '\0';
			str_return = ft_strjoin(str_return, aux);
		}
		if (state < 0)
			return (free_all (str_return, first));
	}
	return (str_return);
}

char	*get_next_line(int fd)
{
	char		*left_str;
	static char	*aux;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux = complete_array(fd, aux);
	if (!aux)
		return (NULL);
	left_str = get_left (aux);
	aux = get_rest (aux);
	return (left_str);
}

/*  int main()
 {
	 	char *line;
int fd;
 	int i = 0;
 	fd = open("texto.txt", O_RDONLY);
 	line = get_next_line(fd);
 	while(line) // && i < 5)
 	{
 		printf("%s", line);
 		// write(1, line, ft_strlen(line));
 		free(line); 		
		// free(line);
	line = get_next_line(fd);
	++i;
 	}
 	// free(line);
 	return(0);
 } */