/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:56:01 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/19 09:06:46 by bjandri          ###   ########.fr       */
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
    while(str[i] && str[i + 1])
    {
        if(str[i] == str[i + 1])
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

    i = 1;
    while(i < ac)
    {
        if(ft_isnumber(av[i]) == 1)
            ft_error_msg("Error\n");
        if(ft_check_doubl(av[i]) == 1)
            ft_error_msg("Error\n");
        i++;
    }
    return (0);
}
