/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:58:09 by Arsene            #+#    #+#             */
/*   Updated: 2022/11/04 15:55:40 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *stash = NULL;
    char        buffer[BUFFER_SIZE + 1];
    int         bytes_read;
    char        *line;
    int         i;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    i =  0;
    while (i < BUFFER_SIZE)
        buffer[i++] = 0;
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(stash);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
        if (ft_strchr_mod(buffer, '\n') > -1)
            break ;
    }
    line = ft_get_line(stash);
    stash = clean_stash(stash);
    if (!line)
    {
        free(line);
        free(stash);
        return (NULL);
    }
    return (line);
}

char    *ft_get_line(char *stash)
{
    char    *clean_line;
    int     i;   
    
    i = 0;
    if (!stash[i])
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    clean_line = malloc(sizeof(char) * (i + 2));
    if (!clean_line)
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        clean_line[i] = stash[i];
        i++;
    }
    if (stash[i] == '\n')
    {
        clean_line[i] = stash[i];
        i++;
    }
    clean_line[i] = '\0';
    return (clean_line);
}

char    *clean_stash(char *stash)
{
    char    *new_stash;
    int     i;
    int     j;
    
    i = 0;
    if (!stash[i])
    {
        free(stash);
        return (NULL);
    }
    while (stash[i] && stash[i] != '\n')
        i++;
    if (i == ft_strlen(stash))
    {
        free(stash);
        return (NULL);
    }
    else
    {
        new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i) + 1);
        if (!new_stash)
            return (NULL);
        i += 1;
        j = 0;
        while (stash[i])
            new_stash[j++] = stash[i++];
        new_stash[j] = '\0';
    } 
    free(stash);
    return (new_stash);
}