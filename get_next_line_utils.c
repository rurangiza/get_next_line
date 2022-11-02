/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:16:30 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/02 17:15:46 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const	char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		i;
	int		nbytes;
	
	nbytes = count * size;
	if (size != 0 && count >= (SIZE_MAX / size))
		return (NULL);
	ptr = malloc(nbytes);
	if (ptr == NULL)
		return (NULL);
	if (nbytes)
	{
		i = 0;
		while (i < nbytes)
			((char *)ptr)[i++] = 0;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		length;
	int		i;
	int		j;

	if (!s1 || !s2)
	{
		free((char *)s1);
		return (NULL);
	}
	length = ft_strlen(s1) + ft_strlen(s2);
	if (!length)
	{
		free((char *)s1);
		return (NULL);
	}
	s3 = malloc(sizeof(char) * (length + 1));
	if (!s3)
		return (0);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[length] = '\0';
	free((char *)s1);
	return (s3);
}

int	found_eol(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *str)
{
	char	*deep_copy;
	int		s_len;
	int		s_index;

	s_len = ft_strlen(str);
	deep_copy = (char *) malloc(sizeof(char) * (s_len + 1));
	if (!deep_copy)
		return (NULL);
	s_index = 0;
	while (str[s_index])
	{
		deep_copy[s_index] = str[s_index];
		s_index++;
	}
	deep_copy[s_index] = '\0';
	return (deep_copy);
}
