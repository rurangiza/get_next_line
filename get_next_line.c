/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:13:09 by arurangi          #+#    #+#             */
/*   Updated: 2022/10/30 16:42:49 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * A function that returns a line read from a file descriptor
*/

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	// Variables locales
	char		buffer[BUFFER_SIZE];
	int			bytes_read;
	static char	*stash;
	int			end_of_line;
	char 		*line;
	// Initialisation
	stash = ft_strdup("");
	int i = 0;
	// Avancer dans le fichier text
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		// Afficher le contenu de 'buffer'
		printf(CBLUE"[%d]+ %s"CRESET, i++, buffer);
		// Ajouter le contenu de 'buffer' dans 'stash'
		stash = ft_strjoin(stash, buffer);
		printf(CCYAN" => %s\n"CRESET, stash);
		// Chercher s'il y a un retour a la ligne
		end_of_line = found_EOL(stash, '\n');
		if(end_of_line != 0)
		{
			// Copy useful line to LINE
			line = ft_substr(stash, 0, end_of_line);
			printf(CGREEN"> %s\n\n"CRESET, line);
			// Remove useless line from STASH
			stash = ft_strdup(stash + end_of_line + 1);
		}
	}
	return (stash);
}
