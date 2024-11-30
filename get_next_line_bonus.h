/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:03:29 by olaaroub          #+#    #+#             */
/*   Updated: 2023/12/07 21:06:49 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

unsigned int	ft_strlen(char *str);
char			*ft_strdup(char *s1);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char *s, unsigned int start, int len);
char			*ft_strchr(char *str, int c);
int				ft_strlcpy(char *dest, char *src, int size);
char			*get_next_line(int fd);

#endif