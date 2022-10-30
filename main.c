/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:59:57 by arurangi          #+#    #+#             */
/*   Updated: 2022/10/30 16:30:35 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("exemple.txt", O_RDONLY);
	printf(CRED "\n------- LINE RETURNED ------\n" CRESET);
	get_next_line(fd);
}

// #include <stdio.h>

// int main(void)
// {
// 	char *str = "BienvenuLami";
// 	char *str2 = str + 5;
// 	printf("%s\n", str2);
// }