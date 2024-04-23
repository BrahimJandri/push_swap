/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:08:09 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/23 10:11:04 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_find_min(t_list *stack)
{
    t_list *min;
    t_list *cur;
	
    if (!stack)
	{
        return NULL;
	}
	
	min = stack;
	cur = stack->next;
    while (cur)
    {
        if (cur->content < min->content)
            min = cur;
        cur = cur->next;
    }
    return min;
}


t_list		*ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list *min;
	int i;

	i = 0;
	min = ft_find_min(*stack_a);
	*stack_a = min;
	while (i < 2)
	{
		ft_pb(stack_a, stack_b);
		min = ft_find_min(*stack_a);
		*stack_a = min;
		i++;
	}
	ft_sort_three(stack_a);
	i = 0;
	while(i < 2)
	{
		ft_pa(stack_a, stack_b);
		i++;
	}
	return(*stack_a);
}
