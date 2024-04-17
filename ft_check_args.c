/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:56:01 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/17 15:52:58 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_check_args(int ac, char **av)
{
    int i;
    int j;

    if(ac < 2)
    {
        ft_printf("error");
        exit(1);
    }
    i = 1;
    while(i < ac)
    {
        j = 0;
        while(av[i][j])
        {
            if(!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][j] != '-')
            {
                ft_printf("error");
                exit(1);
            }
            j++;
        }
        i++;
    }
}

void    ft_check_double(int ac, char **av)
{
    int i;
    int j;
    int k;
    int *tab;

    i = 1;
    tab = (int *)malloc(sizeof(int) * ac);
    while(i < ac)
    {
        j = 0;
        k = 0;
        while(av[i][j])
        {
            if(ft_isdigit(av[i][j]) || av[i][j] == '-')
            {
                tab[k] = ft_atoi(av[i]);
                k++;
            }
            j++;
        }
        j = 0;
        while(j < k)
        {
            if(tab[j] == tab[j + 1])
            {
                ft_printf("error");
                exit(1);
            }
            j++;
        }
        i++;
    }
    free(tab);
}

void    ft_check_int(int ac, char **av)
{
    int i;
    int j;
    int k;
    int *tab;

    i = 1;
    tab = (int *)malloc(sizeof(int) * ac);
    while(i < ac)
    {
        j = 0;
        k = 0;
        while(av[i][j])
        {
            if(ft_isdigit(av[i][j]) || av[i][j] == '-')
            {
                tab[k] = ft_atoi(av[i]);
                k++;
            }
            j++;
        }
        j = 0;
        while(j < k)
        {
            if(tab[j] > 2147483647 || tab[j] < -2147483648)
            {
                ft_printf("error");
                exit(1);
            }
            j++;
        }
        i++;
    }
    free(tab);
}

void    ft_check_all(int ac, char **av)
{
    ft_check_args(ac, av);
    ft_check_double(ac, av);
    ft_check_int(ac, av);
}

