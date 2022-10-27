/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:13:09 by arurangi          #+#    #+#             */
/*   Updated: 2022/10/27 18:24:44 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * A function that returns a line read from a file descriptor
*/

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	char		buffer[6];
	static char	*stash;
	int			length;
	char 		*line;

	stash = "";
	if (fd == -1)
		return (NULL);
	// Move through text 5 bytes at a time
	while (read(fd, buffer, sizeof(5)))
	{
		printf("+ %s\n", buffer);
		// Add buffer content to STASH
		stash = ft_strjoin(stash, buffer);
		printf("===> %s\n", stash);
		// Looks for '\n' in STASH
		length = ft_strchr(stash, '\n');
		if (length > 0)
		{
			// Save the line
			line = ft_substr(stash, 0, length);
			// Erase it from the STASH
			stash = ft_substr(stash, length, 100);
			// Return the line
			return (line);
		}
	}
	if (stash[0])
		return(stash);
	else
		return (NULL);
}

int	found_end_of_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}