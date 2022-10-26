/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:13:09 by arurangi          #+#    #+#             */
/*   Updated: 2022/10/26 18:15:05 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * A function that returns a line read from a file descriptor
*/

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char		buffer[6];
	static char	*stash;
	int			length;
	char 		*line;

	// Check if file descriptor has been provided
	if (fd != -1)
	{
		stash = "";
		while (read(fd, buffer, sizeof(5)) > 0) // Different '0' and '-1'
		{
			// Add buffer content to STASH
			stash = ft_strjoin(stash, buffer);
			// Locate '\n' in STASH
			length = ft_strchr(stash, '\n');
			if (length > 0)
			{
				// Return string till '\n'
				line = ft_substr(stash, 0, length);
				// Erase from stash the content you returned
				stash = ft_substr(stash, length, 10);
			}
			/*
			if (found_end_of_line())
			{
				line = 
			}
			line = 
			*/
		}
		if (stash[0])
			return(stash);
		else
			return (NULL);
		//close(fd);
	}
	else
		return (NULL);
}
