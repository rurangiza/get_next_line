/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:13:09 by arurangi          #+#    #+#             */
/*   Updated: 2022/10/25 14:41:48 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * A function that returns a line read from a file descriptor
*/

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd);

int	main(void)
{
	int			fd;
	char		buffer[6];
	static char	*stash;

	stash = "";
	fd = open("exemple.txt", O_RDONLY);
	if (fd != -1)
	{
		while (read(fd, buffer, sizeof(5)))
		{
			// Add buffer content to STASH
			stash = ft_strjoin(stash, buffer);
			// Locate '\n' in STASH
			if (strchr(stash, '\n'))
			{
				// Return string till '\n'
				return ();
			}
		}
		close(fd);
	}
}

int	find_null()
{
	int i;

	i = 0;
	while (str[i] !=)
}


// Returns 0 if reached end of line

// Read nbytes
	// if successful
			// Save in buffer
			// Return nbytes
			// Add buffer content to STASH
					// if there is a '\0'
						// Return saved content till '\0' (get_next_line)
						// Erase content you returned from the STASH
					// if not
	// if end of file or error
			// save the few read characters to buffer
			// return 0