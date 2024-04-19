/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:56:01 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/19 12:09:31 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_isnumber(char *str)
{
    int i;
    
    i = 0;
    if((str[i] == '-' && str[i + 1] != 0) || (str[i] == '+' && str[i + 1] != 0))
        i++;
    while(str[i])
    {
        if(!ft_isdigit(str[i++]))
            return (1);
    }
    return (0);
}

static int ft_check_doubl(char *str)
{
    int i = 0;
    int j = 0;
    int *tab;
    int len;
    
    len = ft_strlen(str);
    tab = (int *)malloc(sizeof(int) * len);
    while(str[i])
    {
        tab[i] = str[i];
        i++;
    }
    i = 0;
    while(i < len)
    {
        j = i + 1;
        while(j < len)
        {
            if(tab[i] == tab[j])
            {
                free(tab);
                return (1);
            }
            j++;
        }
        i++;
    }
    free(tab);
    return (0);
}

static int  ft_check_int(int len, char *str)
{
    long tmp;
    int i;

    i = 0;
    while(i < len)
    {
        tmp = ft_atol(&str[i]);
        if(tmp > 2147483647 || tmp < -2147483648)
            return (1);
        i++;
    }
    return (0);
}

static void    ft_error_msg(char *str)
{
    ft_printf("%s", str);
    exit(0);
}

int			ft_check_args(int ac, char **av)
{
    int i;
    int len;
    
    i = 1;
    len = ac -1;
    while(i < ac)
    {
        if(ft_isnumber(av[i]) == 1)
            ft_error_msg("Error not number\n");
        if(ft_check_doubl(av[i]) == 1)
            ft_error_msg("Error double\n");
        if(ft_check_int(len, av[i]))
            ft_error_msg("Error max or min\n");
        i++;
    }
    return (0);
}
