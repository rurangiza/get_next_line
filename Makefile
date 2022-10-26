# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 11:23:31 by arurangi          #+#    #+#              #
#    Updated: 2022/10/26 17:42:55 by Arsene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			ft_get_next_line.c \
				ft_get_next_line_utils.c

OBJS =			${SRCS:.c=.o}

CC =			cc ${FLAGS}
FLAGS =			-Wall -Wextra -Werror
OPTIONS =		-D BUFFER_SIZE=42

RM =			rm -f

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM}

.PHONY:			all clean