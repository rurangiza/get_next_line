/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:13:09 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/01 18:12:18 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * A function that returns a line read from a file descriptor
*/

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (stash)
		printf(CRED"static = %s"CRESET, stash);
	if (!stash)
		stash = ft_strdup("");
	if (fd == -1 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	stash = get_raw_line(fd, stash);
	printf(CGREEN"stash = %s"CRESET, stash);
	if (!stash)
		return (NULL);
	line = clean_line(stash);
	stash = clean_stash(stash);
	return (line);
}

/* Avancer dans fichier jusqu'a 1)un retour a la ligne ou 2)fin de phrase */
char *get_raw_line(int fd, char *stash)
{
	int bytes_read;
	char buffer[BUFFER_SIZE + 1];

	bytes_read = 1;
	//printf(CBLUE "\nstash000= %s" CRESET, stash);
	printf("\nvaleur de fct %d\n", found_eol(buffer, '\n'));
	while (bytes_read > 0 && !found_eol(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		printf(CBLUE "\nstash000= %s" CRESET, buffer);
		if (bytes_read == -1)
		{
			free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		//if (found_eol(buffer, '\n'))
		//	break ;
	}
	return (stash);
}

char	*clean_line(char *stash)
{
	int		len;
	int		i;
	char	*line;

	if (!stash)
		return (NULL);
	len = 0;
	while (stash[len] != '\n' && stash[len])
		len++;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		line[i] = stash[i];
		i++;
	}
	line[len + 1] = '\0';
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
	if (stash[i] == '\n')
		i++;
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
		return (NULL);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}
