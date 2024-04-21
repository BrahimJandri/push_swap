/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:25:19 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/21 18:28:39 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list    *ft_sort_three(t_list *stack)
{
    if ( stack->content >  stack->next->content
        &&  stack->content <  stack->next->next->content)
    {
        ft_sa(stack);
        ft_printf("sa\n");
    }
    else if ( stack->content >  stack->next->content
        &&  stack->content >  stack->next->next->content)
    {
        ft_sa(stack);
        ft_rra(stack);
        ft_printf("sa\nrra\n");
    }
    else if ( stack->content <  stack->next->content
        &&  stack->content >  stack->next->next->content)
    {
        ft_ra(stack);
        ft_printf("ra\n");
    }
    else if ( stack->content <  stack->next->content
        &&  stack->content <  stack->next->next->content)
    {
        ft_sa(stack);
        ft_printf("sa\n");
    }
    return (stack);
}


