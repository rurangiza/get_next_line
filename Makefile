# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 11:23:31 by arurangi          #+#    #+#              #
#    Updated: 2022/10/24 11:30:51 by arurangi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			ft_get_next_line.c \
				ft_get_next_line_utils.c

CC =			cc ${FLAGS}
FLAGS =			-Wall -Wextra -Werror
OPTIONS =		-D BUFFER_SIZE=42

RM =			rm -f

all :			${SRCS}

clean:			${RM} a.out

.PHONY:			all clean