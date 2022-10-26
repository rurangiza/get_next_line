/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:46:50 by Arsene            #+#    #+#             */
/*   Updated: 2022/10/26 09:52:16 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char *stash = "";
    char *buffer = "Arsene";
    stash = ft_strjoin(stash, buffer);
    printf("Stash: %s\n", stash);
    char *buffer2 = " Booba";
    stash = ft_strjoin(stash, buffer2);
    printf("\nStash: %s\n", stash);
}