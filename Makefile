# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 11:23:31 by arurangi          #+#    #+#              #
#    Updated: 2022/10/30 13:11:37 by arurangi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES =			get_next_line.c \
					get_next_line_utils.c

FLAGS =			-Wall -Wextra -Werror
CC =			gcc ${FLAGS}

RM =			rm -f

NAME=			runthis

all:			${NAME}

${NAME}:
				${CC} ${SRC_FILES} -o ${NAME}

clean:
				${RM} ${OBJ_FILES}

fclean:			clean
				${RM}

.PHONY:			all clean