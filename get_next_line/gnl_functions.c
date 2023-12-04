/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:04:27 by olaaroub          #+#    #+#             */
/*   Updated: 2023/12/04 15:13:46 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}
char	*ft_strdup( char *s1)
{
	int		i;
	char	*nv;
	int	len;

	i = 0;
	if(!s1)
		return NULL;
	len = ft_strlen(s1);
	nv = malloc(sizeof(char) * len + 1);
	if (!nv)
		return (NULL);
	while (s1[i])
	{
		nv[i] = s1[i];
		i++;
	}
	nv[i] = '\0';
	return (nv);
}

int check_newline(char src)
{
    if(src == '\n')
        return 1;
    return 0;
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	char	*buff;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
    if(!s1 && !s2)
		return NULL;
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	buff = ptr;
	while (*s1)
	{
		*buff++ = *s1++;
	}
	while (*s2)
	{
		*buff++ = *s2++;
	}
	*buff = '\0';
	return (ptr);
}
char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (s + start), len + 1);
	return (ptr);
}
char	*ft_strchr(char *str, int c)
{
	int	i;
	char	*buff;

	buff = (char *)str;
	i = 0;
	while (i <= ft_strlen(buff))
	{
		if (buff[i] == (char)c)
			return (buff + i);
		i++;
	}
	return (NULL);
}

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;
	int	lenght;
	char	*buf;

	buf = (char *)src;
	i = 0;
	while (src[i])
	{
		i++;
	}
	lenght = i;
	i = 0;
	if (size != 0)
	{
		while (buf[i] && i < size - 1)
		{
			dest[i] = buf[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (lenght);
}
