/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:58:16 by Arsene            #+#    #+#             */
/*   Updated: 2022/11/06 16:38:03 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
// #include "assets.h"
// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
//     int     fd;
//     char    *str;

//     fd = open("file.txt", O_RDONLY);
//     while (1)
//     {
//         str = get_next_line(fd);
//         if (str == NULL)
//             break ;
//         printf(CGREEN"%s"CRESET, str);
//     }
//     close (fd);
//     return (0);
// }