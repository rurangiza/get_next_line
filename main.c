/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:59:57 by arurangi          #+#    #+#             */
/*   Updated: 2022/10/31 13:46:07 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// to remove
#include <stdio.h>
//#define BUFFER_SIZE 26


// to remove

int	main(void)
{
	int	fd;

	fd = open("exemple.txt", O_RDONLY);
	printf("\n------- LINE RETURNED ------\n");
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}
