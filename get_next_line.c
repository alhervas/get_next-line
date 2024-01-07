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


int	enter(char *sta)
{
	int  i;

	i = -1;
	while(sta[++i])
	{
		if(sta[i] == '\n')
			return (0);
	}
	return (1);
}

char	*read_f(int fd, char *sta)
{
	int		a;
	int		i;
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;

	a = 1;
	while(a > 0)
	{
		if (!enter(sta))
			return (sta);
		a = read(fd, buffer, BUFFER_SIZE);
		//printf("A-> %d\n", a);
		if (a == 0)
			return (sta);
		if (a < 0)
		{
			free (sta);
			return (NULL);
		}
		buffer[a] = '\0';
		aux = ft_strjoin(sta, buffer);
		i = -1;
		while (sta[++i])
		{
			if(sta[i] == '\n')
			{
				a = -1;
				break;
			}
		}
	}
	//free (str);
	return (sta);
}

char	*ft_line(char *buffer)
{
	char *aux;
	int i;

	if (!buffer[0])
		return (NULL);
	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
		{
			i++;
			break;
		}
	}
	if (!buffer[i])
		return (buffer);
	aux = malloc (sizeof (char *) + i + 1);
	i = -1;
	while (buffer[++i])
	{
		aux[i] = buffer[i];
		if (buffer[i] == '\n')
			break;
	}
	aux[i + 1] = '\0';
	return(aux);
}

char	*ft_next(char *buffer)
{
	char *aux;
	int i;
	int	j;

	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
			break;
	}
	if (!buffer[i])
		return (NULL);
	j = i;
	while (buffer[j])
		j++;
	
	aux = malloc (sizeof (char *) + (j - i) + 1);
	aux[j - i] = '\0';
	j = -1;
	while (buffer[i++])
	{
		aux[++j] = buffer[i];
		if (buffer[i] == '\n')
			break;
	}
	return(aux);
}

char	*get_next_line(int fd)
{
	static char	*sta;
	char		*line;
	char		*aux;

	if (fd < 0 || BUFFER_SIZE  < 0)
		return (NULL);
	if (!sta)
	{
		sta = malloc(sizeof(char *) * 1);
		*sta = '\0';
	}
	aux = read_f (fd, sta);
	if (!aux)
		return(NULL);
	line = ft_line(aux);
	sta = ft_next(aux);
	return (line);
}

/* int	main(void)
{
	int fd;
	char	*c;
	int i = 0;

	fd = open("aaa.txt", O_RDONLY);
	c = get_next_line(fd);
	while (c && i++ < 300)
	{
		printf("%s", c);
		c = get_next_line(fd);
	}
	system("leaks -q a.out");
	close(fd);
} */
