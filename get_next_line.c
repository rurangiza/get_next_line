/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:13:09 by arurangi          #+#    #+#             */
/*   Updated: 2022/10/30 18:39:47 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * A function that returns a line read from a file descriptor
*/

#include "get_next_line.h"

char	*save_line(char *stash);
char	*clean_stash(char *stash);

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*stash;
	char		*line;

	stash = ft_strdup("");
	if (fd == -1)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		stash = ft_strjoin(stash, buffer);
		if (found_eol(buffer, '\n'))
		{
			// Enregistre la phrase
			line = save_line(stash);
			// Netoie le stash
			stash = clean_stash(stash);
			// Renvoi la ligne
			return (line);
		}
	}
	return (0);
}

char	*save_line(char *stash)
{
	int		len;
	int		i;
	char	*line;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	len = i + 1;
	line = malloc(sizeof(char) * len);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i) + 1);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}
