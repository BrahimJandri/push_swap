/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:57:07 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/01 09:11:51 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		last = ft_last_stack(*stack);
		second = (*stack)->next;
		last->next = first;
		first->next = NULL;
		*stack = second;
	}
}

void	ft_ra(t_stack **stack, int c)
{
	ft_rotate(stack);
	if (!c)
		ft_printf("ra\n");
}

void	ft_rb(t_stack **stack, int c)
{
	ft_rotate(stack);
	if (!c)
		ft_printf("rb\n");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, int c)
{
	ft_ra(stack_a, 1);
	ft_rb(stack_b, 1);
	if (c)
		ft_printf("rr\n");
}
