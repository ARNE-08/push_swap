/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:30:23 by psaengha          #+#    #+#             */
/*   Updated: 2023/08/23 15:02:46 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// ! comeback to chanhe printf to ft_printf

void    check_emptyString(int ac, char **av)
{
    int i;
    int j;
    
    i = 1;
    while (i < ac)
    {
        if (av[i][0] == '\0')
        {
            printf("Error1\n");
            exit(0);
        }    
        i++;
    }
}

void    check_nonNumeric(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        while (j < ft_strlen(av[i]))
        {
            if (av[i][j] != ' ' && (av[i][j] < '0' || av[i][j] > '9'))
            {
                printf("Error2\n");
                exit(0);
            }
            j++;
        }
        i++;
    }
}

// ! check MAX/MIN
void    check_limit(int ac, char **av)
{
    int     i;
    long    temp;

    i = 1;
    while (av[i])
    {
        if (ft_strlen(av[i] > 10))
        {
            printf("Error4\n");
            exit(0);
        }
        i++;
    }
    // ! check when the length is still 10
}

// ! check duplicate numeric
void    check_duplicate(int ac, char **av)
{
    int i;
    int j;
    int temp;

    if (ac == 2)
    {
        j = 0;
        while (av[1][j] != '\0' && av[1][j] == ' ')
            j++;
        temp = ft_atoi(av[1][j]);
        while (j < ft_strlen(av[1]))
        {
            temp = ft_atoi(av[1][j]);
            i = j + 1;
            while (i < ft_strlen(av[1]))
            {
                if (av[1][i] != ' ' && temp == ft_atoi(av[1][i]))
                {
                    printf("Error3\n");
                    exit(0);
                }
                i++;
            }
            j++;
        }
    }
}