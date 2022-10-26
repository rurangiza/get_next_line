/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:46:50 by Arsene            #+#    #+#             */
/*   Updated: 2022/10/26 18:02:45 by Arsene           ###   ########.fr       */
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
    return (0);
}