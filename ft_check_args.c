/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:56:01 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/18 14:15:29 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isnumber(char *str)
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

int			ft_check_args(int ac, char **av)
{
    int i;

    (void)ac;
    i = 1;
    while(av[i])
    {
        if(ft_isnumber(av[i++]) == 1)
        {
            ft_printf("Error\n");
            break;
        }
    }
    return 0;
}
