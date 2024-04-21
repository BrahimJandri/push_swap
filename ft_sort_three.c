/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:25:19 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/21 14:38:48 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list    *ft_sort_three(t_list *stack)
{
    if (stack->content > stack->next->content
        && stack->content < stack->next->next->content)
        ft_sa(stack);
    else if (stack->content > stack->next->content
        && stack->content > stack->next->next->content)
    {
        ft_sa(stack);
        ft_rra(stack);
    }
    else if (stack->content < stack->next->content
        && stack->content > stack->next->next->content)
        ft_ra(stack);
    else if (stack->content < stack->next->content
        && stack->content < stack->next->next->content)
    {
        ft_sa(stack);
        ft_ra(stack);
    }
    return (stack);
}

