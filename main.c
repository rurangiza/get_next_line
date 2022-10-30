/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:59:57 by arurangi          #+#    #+#             */
/*   Updated: 2022/10/30 16:58:16 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// to remove
#include <stdio.h>
//#define BUFFER_SIZE 26

#define CRED     "\x1b[31m"
#define CGREEN   "\x1b[32m"
#define CYELLOW  "\x1b[33m"
#define CBLUE    "\x1b[34m"
#define CMAGENTA "\x1b[35m"
#define CCYAN    "\x1b[36m"
#define CRESET   "\x1b[0m"
// to remove

int	main(void)
{
	int	fd;

	fd = open("exemple.txt", O_RDONLY);
	printf(CRED "\n------- LINE RETURNED ------\n" CRESET);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}

// #include <stdio.h>

// int main(void)
// {
// 	char *str = "BienvenuLami";
// 	char *str2 = str + 5;
// 	printf("%s\n", str2);
// }
