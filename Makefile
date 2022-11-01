# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 11:23:31 by arurangi          #+#    #+#              #
#    Updated: 2022/11/01 18:03:58 by arurangi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
				@gcc -Wall -Wextra -Werror *.c -o runthis -D BUFFER_SIZE=6
				@./runthis


clean:
				@rm runthis

.PHONY:			all clean