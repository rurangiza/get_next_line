/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:13:42 by arurangi          #+#    #+#             */
/*   Updated: 2022/10/27 15:15:33 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
// int     found_end_of_line(char *s);
int     ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strdup(const char *str);
size_t  ft_strlen(const	char *str);

#endif