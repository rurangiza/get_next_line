/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:13:42 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/02 17:15:15 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		found_eol(char *buffer);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const	char *str);

void	*ft_calloc(size_t count, size_t size);

char	*get_raw_line(int fd, char *stash);
char	*clean_line(char *stash);
char	*clean_stash(char *stash);

#endif