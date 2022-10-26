/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:13:09 by arurangi          #+#    #+#             */
/*   Updated: 2022/10/26 11:46:13 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * A function that returns a line read from a file descriptor
*/

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd);

void green () {
  printf("\033[0;32m");
}
void reset () {
  printf("\033[0m");
}

int main(void)
{
	int fd;
	char buffer[6];
	static char *stash;
	int length;

	stash = "";
	fd = open("exemple.txt", O_RDONLY);
	// Check if file descriptor has been provided
	if (fd != -1)
	{
		while (read(fd, buffer, sizeof(5)) > 0) // Different '0' and '-1'
		{
			// Add buffer content to STASH
			stash = ft_strjoin(stash, buffer);
			// Locate '\n' in STASH
			length = ft_strchr(stash, '\n');
			if (length > 0)
			{
				// Return string till '\n'
				//return (ft_substr(stash, 0, length));
				green();
				printf("\n%s\n", ft_substr(stash, 0, length));
				reset();
				// Erase from stash the content you returned
				stash = ft_substr(stash, length, 10);
			}
		}
		if (stash[0])
		{
			//green();
			printf("\n%s\n", stash);
			//reset();
		}
		close(fd);
	}
	else
		return ; // NULL
}
