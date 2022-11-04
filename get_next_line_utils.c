/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:58:12 by Arsene            #+#    #+#             */
/*   Updated: 2022/11/04 15:46:13 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const	char *str)
{
	int	len;

	len = 0;
	if (str)
	{
		while (str[len])
			len++;
	}
	return (len);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	int	i;
	int	j;
	char	*tmp;

	if (!stash)
		stash = ft_strdup("");
	if (!stash || !buffer)
		return (NULL);
	tmp = malloc(sizeof(char) * ((ft_strlen(stash) + ft_strlen(buffer)) + 1));
	if (tmp == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (stash)
		while (stash[++i] != '\0')
			tmp[i] = stash[i];
	while (buffer[j] != '\0')
		tmp[i++] = buffer[j++];
	tmp[ft_strlen(stash) + ft_strlen(buffer)] = '\0';
	free(stash);
	return (tmp);
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

int	ft_strchr_mod(const char *s, char ch)
{
	int		index;

	if (s)
	{
		index = 0;
		while (s[index])
		{
			if (s[index] == ch)
				return (index);
			index++;
		}
	}
	return (-1);
}