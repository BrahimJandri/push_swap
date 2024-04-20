/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:56:01 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/20 10:48:30 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_isnumber(char *str)
{
    int i;
    
    i = 0;
    if ((str[i] == '-' && str[i + 1] != '\0') || (str[i] == '+' && str[i + 1] != '\0'))
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return 1;
        i++;
    }
    return 0;
}


static int ft_check_int(char *str)
{
    long tmp;
    
    tmp = ft_atol(str);
    if (tmp > 2147483647 || tmp < -2147483648)
        return 1;
    return 0;
}

static int ft_check_doubl(int len, char **str)
{
    int i;
    int j;
    
    i = 1;
    while(i < len - 1)
    {
        j = i + 1;
        while(j < len)
        {
            if(ft_atoi(str[i]) == ft_atoi(str[j]))
                return (1);
            j++;
        }
        i++;
    }
    return 0;
}

static void ft_error_msg(char *str)
{
    ft_printf("%s", str);
    exit(0);
}

static int ft_check_empty(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(str[i] != ' ' || str[i] != '\t')
            return 0;
        i++;
    }
    return 1;
}

static void ft_free_str(char **str)
{
    int i = 0;
    
    while (str[i] != NULL)
    {
        free(str[i]);
        i++;
    }
    free(str);
}
int ft_check_args(int ac, char **av)
{
    int i;
    int j;
    char **str;
    
    i = 1;
    if (ft_check_doubl(ac, av))
        ft_error_msg("Error double\n");
    while (i < ac)
    {
        str = ft_split(av[i], ' ');
        if (!str)
            ft_error_msg("Memory allocation failed\n");
        j = 0;
        while (str[j])
        {
            if (ft_isnumber(str[j]))
                ft_error_msg("Error not number\n");
            if(ft_check_empty(str[i]))
                ft_error_msg("Error one arg is Empty\n");
            if (ft_check_int(str[j]))
                ft_error_msg("Error max or min\n");
            j++;
        }   
        ft_free_str(str);
        i++;
    }
    return 0;
}
