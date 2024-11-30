/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:35:21 by olaaroub          #+#    #+#             */
/*   Updated: 2023/12/07 16:49:54 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*nv;
	int		len;

	i = 0;
	if (s1 == NULL || s1[0] == '\0')
		return (NULL);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	char	*buff;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
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

char	*ft_strchr(char *str, int c)
{
	unsigned int	i;
	char			*buff;

	buff = (char *)str;
	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (i <= ft_strlen(buff))
	{
		if (buff[i] == (char)c)
			return (buff + i);
		i++;
	}
	return (NULL);
}
