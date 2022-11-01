/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:13:42 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/01 18:10:32 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// TMP
#define CRED     "\x1b[31m"
#define CGREEN   "\x1b[32m"
#define CYELLOW  "\x1b[33m"
#define CBLUE    "\x1b[34m"
#define CMAGENTA "\x1b[35m"
#define CCYAN    "\x1b[36m"
#define CRESET   "\x1b[0m"

#include <stdio.h>
//

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		found_eol(char *buffer, char ch);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const	char *str);

char	*get_raw_line(int fd, char *stash);
char	*clean_line(char *stash);
char	*clean_stash(char *stash);

#endif