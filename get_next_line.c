/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:13:09 by arurangi          #+#    #+#             */
/*   Updated: 2022/10/30 17:00:40 by arurangi         ###   ########.fr       */
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
	int			end_of_line;
	char		*line;

	stash = ft_strdup("");
	if (fd == -1)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		stash = ft_strjoin(stash, buffer);
		end_of_line = found_eol(stash, '\n');
		if (end_of_line != 0)
		{
			line = ft_substr(stash, 0, end_of_line + 1);
			stash = ft_strdup(stash + end_of_line);
			return (line);
		}
	}
	return (0);
}
