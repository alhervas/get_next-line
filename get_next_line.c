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

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*cadena;
	int		bytes;
	char	*new_fd;

	cadena = malloc(BUFFER_SIZE + 1);
	new_fd = malloc(1000);
	bytes = read(fd, cadena, BUFFER_SIZE);
	new_fd = ft_strchr(cadena, '\n') + 1;
	return(cadena);
}

int	main()
{
	int		fd;
	//char	*c;

	fd = open("aaa.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}