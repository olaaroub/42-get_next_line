/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:20:11 by alassiqu          #+#    #+#             */
/*   Updated: 2023/12/07 21:15:21 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

// mandatory tests !
int	main_mandatory(void)
{
	int	fd;

	fd = open("file.txt", O_RDWR);
	for(int i = 0; i < 2; i++)
	{
		printf("call NO %d --> %s", i, get_next_line(fd));
	}
	// printf("1st call --> %s \n", get_next_line(fd));
	// printf("2nd call --> %s \n", get_next_line(fd));
	// printf("3rd call --> %s \n", get_next_line(fd));
	// printf("4th call --> %s \n", get_next_line(fd));
	// printf("5th call --> %s \n", get_next_line(fd));
	// printf("6th call --> %s \n\n", get_next_line(fd));
	// printf("6th call --> %s \n\n", get_next_line(fd));
	// printf("6th call --> %s \n\n", get_next_line(fd));
	// printf("6th call --> %s \n\n", get_next_line(fd));
	// printf("6th call --> %s \n\n", get_next_line(fd));
	// printf("6th call --> %s \n\n", get_next_line(fd));
	// printf("6th call --> %s \n\n", get_next_line(fd));
	// printf("6th call --> %s \n\n", get_next_line(fd));
	// printf("6th call --> %s \n\n", get_next_line(fd));
	// printf("6th call --> %s \n\n", get_next_line(fd));
	// printf("6th call --> %s \n\n", get_next_line(fd));
	// printf("6th call --> %s \n\n", get_next_line(fd));
	// printf("6th call --> %s \n\n", get_next_line(fd));
	// printf("6th call --> %s \n\n", get_next_line(fd));
	// printf("6th call --> %s \n\n", get_next_line(fd));
	close(fd);
	return (0);
}

int	main_error_management(void)
{
	printf("Error management -> %s\n", get_next_line(42));
	printf("Error management -> %s\n", get_next_line(1337));
	printf("Error management -> %s\n", get_next_line(-1337));
	printf("Error management -> %s\n", get_next_line(-1));
	printf("Error management -> %s\n", get_next_line(11));
	printf("Error management -> %s\n", get_next_line(999999999));
	return (0);
}

// Why we do need bonus ?
int	main_why_bonus(void)
{
	int	fd;
	int	fd0;
	int	fd1;

	fd = open("empty_line.txt", O_RDWR, 0777);
	fd0 = open("file.txt", O_RDWR, 0777);
	fd1 = open("short_line.txt", O_RDWR, 0777);
	printf("(fd) 1st call -> %s \n", get_next_line(fd));
	printf("(fd) 2nd call -> %s \n", get_next_line(fd));
	printf("(fd0) 1st call -> %s \n", get_next_line(fd0));
	printf("(fd0) 2nd call -> %s \n", get_next_line(fd0));
	printf("(fd1) 1st call -> %s \n", get_next_line(fd1));
	printf("(fd1) 2nd call -> %s \n", get_next_line(fd1));
	printf("(fd0) 3rd call -> %s \n", get_next_line(fd0));
	printf("(fd0) 4th call -> %s \n", get_next_line(fd0));
	printf("(fd1) 3rd call -> %s \n", get_next_line(fd1));
	printf("(fd1) 4th call -> %s \n\n", get_next_line(fd1));
	printf("(fd1) 4th call -> %s \n\n", get_next_line(fd1));

	printf("(fd) 3rd call -> %s \n", get_next_line(fd));
	close(fd);
	close(fd0);
	close(fd1);
	return (0);
}

int	main(void)
{
	// Large BUFFER_SIZE (>1024):
	// Small BUFFER_SIZE (< 8, and 1):
	// BUFFER_SIZE exactly the length of the line to read:
	// (Multiple/Single) Long line (2k+ characters):
	// (Multiple/Single) Short line (< 4 characters, even 1):
	// (Multiple/Single) Empty line
	// main_mandatory();
	// fd error !
	// main_error_management();
	// Why do we need bonus ??
	main_why_bonus();
}
