/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:13:09 by arurangi          #+#    #+#             */
/*   Updated: 2022/10/31 12:40:49 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * A function that returns a line read from a file descriptor
*/

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*stash;
	char		*line;

	if (!stash)
		stash = ft_strdup("");
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		stash = ft_strjoin(stash, buffer);
		if (found_eol(buffer, '\n'))
		{
			line = save_line(stash);
			stash = clean_stash(stash);
			return (line);
		}
	}
	return (NULL);
}

char	*save_line(char *stash)
{
	int		len;
	int		i;
	char	*line;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	len = i + 2;
	line = malloc(sizeof(char) * len);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		line[i] = stash[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}
