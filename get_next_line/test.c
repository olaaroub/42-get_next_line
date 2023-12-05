/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:24:43 by olaaroub          #+#    #+#             */
/*   Updated: 2023/12/04 22:52:07 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *gnl(int fd)
{
    static  char *stat;
    char          *tmp;
    char           *buf;
    ssize_t         readed;
    int         to_allocate;


    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return NULL;
    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if(!buf)
        return NULL;

    readed = 1;
    tmp = NULL;
    int i = 0;
    while (readed)
    {
        readed = read(fd, buf, BUFFER_SIZE);
        if((readed == 0 && !buf) || buf[0] == '\0')
            return (NULL);
        buf[readed] = '\0';
        tmp = ft_strdup(stat);
        free(stat);
        stat = NULL;
        stat = ft_strjoin(tmp, buf);
        free(tmp);
        tmp = NULL;
        if(ft_strchr(buf, '\n'))
            break;
    }

    char    *line;
    char    *newline;
    if (ft_strchr(stat, '\n'))
    {
        newline = ft_strchr(stat, '\n') + 1;
        to_allocate = newline - stat;
        line = ft_substr(stat, 0, to_allocate);
        free(stat);
        stat = NULL;
        stat = ft_strdup(newline);
        newline = NULL;
    }
    else
    {
        line = ft_strdup(stat);
    }
    return line;
}

int main()
{
    int fd;

    fd = open("file.txt", O_RDONLY);
    printf("result number 1 : %s",gnl(fd));
    printf("result number 2 : %s",gnl(fd));
    printf("result number 3 : %s",gnl(fd));

}