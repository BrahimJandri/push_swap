/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:57:07 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/28 11:47:55 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		last = ft_lstlast(*stack);
		second = (*stack)->next;
		last->next = first;
		first->next = NULL;
		*stack = second;
	}
}

void	ft_ra(t_list **stack)
{
	ft_rotate(stack);	
	ft_printf("ra\n");
}

void	ft_rb(t_list **stack)
{
	ft_rotate(stack);	
	ft_printf("rb\n");
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
	ft_printf("rr\n");
}
