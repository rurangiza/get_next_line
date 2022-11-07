/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:41:04 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/07 16:01:15 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_strlen(const	char *str);
char	*ft_strjoin_mod(char *old_stash, char *buff);
char	*ft_strdup(const char *str);
int		ft_strchr_mod(const char *s, char ch);

char	*get_next_line(int fd);
char	*save_raw_line(int fd, char *stash);
char	*trim_right(char *raw_line);
char	*trim_left(char *stash);
char	*free_stash(char *stash);

#endif