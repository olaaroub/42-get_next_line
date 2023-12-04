/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:50:01 by olaaroub          #+#    #+#             */
/*   Updated: 2023/12/03 20:22:28 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *stat;
    char        *buff;
    char        *str;
    int         to_allocate;
    int         bytes_readed;

    bytes_readed = 1;
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return NULL;
    str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!str)
        return ( NULL);
    while(bytes_readed > 0)
    {
        bytes_readed = read(fd, str, BUFFER_SIZE);
        if(bytes_readed == 0 || !str || str[0] == '\0')
            return( free(stat), NULL);
        buff = ft_strdup(stat);
        free(stat);
        stat = ft_strjoin(buff, str);
        if(ft_strchr(stat, '\n'))
            break;
    }
    return stat;
    char    *line;
    char    *newline;

    newline = ft_strchr(stat, '\n') + 1;
    if(newline)
    {
        to_allocate = stat - newline;
        line = ft_substr(stat, 0, to_allocate);
        buff = ft_strdup(newline);
        free(stat);
        stat = buff;
    }
    else
        line = ft_strdup(stat);
    return(free(buff),free(newline), line);
}

int main(){
    int fd;

    fd = open("file.txt", O_RDONLY);

    printf("%s", get_next_line(fd));
}
