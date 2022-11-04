/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:58:07 by Arsene            #+#    #+#             */
/*   Updated: 2022/11/04 06:50:00 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

// #include <stdio.h>
// #include "assets.h"

char    *get_next_line(int fd);
int     ft_strlen(const	char *str);
char    *ft_strjoin(char *old_stash, char *buff);
char    *ft_strdup(const char *str);
char    *ft_substr(char const *s, int start, size_t len);
int     ft_strchr_mod(const char *s, char ch);

char    *ft_get_line(char *raw_line);
char    *clean_stash(char *stash);

#endif