/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:00:53 by ster-min          #+#    #+#             */
/*   Updated: 2021/02/02 17:15:43 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

int		get_next_line(int fd, char **line);
char	*get_line(char *str, int len);
char	*ft_strjoin(char *string, char *buff);
size_t	ft_strlen_gnl(const char *s);
char	*ft_substr(char const *s, int len);

#endif
