/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:16:30 by arurangi          #+#    #+#             */
/*   Updated: 2022/10/31 11:25:43 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * Calculates length of a given string
*/

size_t	ft_strlen(const	char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
 * Combines two strings to create a new one (with memory allocation)
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		length;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
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
	s3[i + j] = '\0';
	return (s3);
}

/*
 * Locates first occurence of character {c} in string {s}
*/

int	found_eol(const char *buffer, char ch)
{
	int		i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/*
 * Returns a substring of {s}
 * Begins at index {start} and of maximum size {len}
*/

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char		*substr;
	size_t		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	while (s[start + i] && i < len)
		i++;
	len = i;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && ((char *)s)[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/*
 * Duplicate a string (Deep copy)
 *
 * Returns : the deep copy
*/

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
