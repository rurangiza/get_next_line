/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:58:16 by Arsene            #+#    #+#             */
/*   Updated: 2022/11/07 15:17:54 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd_1;
	int		fd_2;
	int		fd_3;
	int		index;

	fd_1 = open("file_1", O_RDONLY);
	fd_2 = open("file_2", O_RDONLY);
	fd_3 = open("file_3", O_RDONLY);
	index = 0;
	while (index < 4)
	{
		printf("[1] %s\n", get_next_line(fd_1));
		printf("[2] %s\n", get_next_line(fd_2));
		printf("[3] %s\n", get_next_line(fd_3));
		index++;
	}
	close(fd_1);
	close(fd_2);
	close(fd_3);
	return (0);
}
