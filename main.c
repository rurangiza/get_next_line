/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:46:50 by Arsene            #+#    #+#             */
/*   Updated: 2022/10/27 08:27:45 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *text;
    
    fd = open("exemple.txt", O_RDONLY);
    while (get_next_line(fd))
    {
        text = get_next_line(fd);
        printf("%s", text);
    }
    close(fd);
    return (0);
}