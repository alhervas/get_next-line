/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhervas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:41:28 by alhervas          #+#    #+#             */
/*   Updated: 2023/02/22 17:41:30 by alhervas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

#ifndef BUFFER_SIZE	
 # define BUFFER_SIZE 42
#endif
int		ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *b, size_t len);
char	*get_next_line(int fd);

#endif
