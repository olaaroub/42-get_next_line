/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:05:12 by olaaroub          #+#    #+#             */
/*   Updated: 2023/12/04 22:24:19 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE  10
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	ft_strlen( char *str);
char	*ft_strdup( char *s1);
char	*ft_strjoin(char *s1, char *s2);
int     check_newline(char src);
char	*ft_substr(char *s, unsigned int start, int len);
char	*ft_strchr( char *str, int c);
int	ft_strlcpy(char *dest,char *src, int size);


#endif