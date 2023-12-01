/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:50:12 by olaaroub          #+#    #+#             */
/*   Updated: 2023/12/01 23:21:18 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int     fd;
    char    buf[256];
    int    chars_read;

    fd = open("file.txt",O_RDONLY);

    while((chars_read = read(fd, buf, 10)))
    {
        buf[chars_read] = '\0';
        printf("- %s\n", buf);
    }

}