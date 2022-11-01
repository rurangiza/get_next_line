/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:59:57 by arurangi          #+#    #+#             */
/*   Updated: 2022/11/01 18:02:14 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// to remove
#include <stdio.h>

void	print_lines(int fd, int count);

int	main(void)
{
	int	fd;
	fd = open("exemple.txt", O_RDONLY);
	int	i = 0;
	char	*str;

	while (i < 5)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		printf("gnl[%d] = %s", i++, str);
	}
	//print_lines(fd, 11);
	
	close(fd);
}

// void	print_lines(int fd, int count)
// {
// 	int i;
	
// 	i = 0;
// 	while (i < count)
// 	{
// 		if (i % 2 == 0)
// 			printf(CBLUE"%s"CRESET, get_next_line(fd));
// 		else
// 			printf(CGREEN"%s"CRESET, get_next_line(fd));
// 		i++;
// 	}
// }