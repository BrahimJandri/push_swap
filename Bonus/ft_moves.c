/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:34:41 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/11 09:43:15 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push_bonus(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	if ((*stack_a) != NULL)
	{
		first = *stack_a;
		second = (*stack_a)->next;
		(*stack_a)->next = NULL;
		*stack_a = second;
		ft_add_front_b(stack_b, first);
	}
}

void	ft_rotate_bonus(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		last = ft_last_stack_b(*stack);
		second = (*stack)->next;
		last->next = first;
		first->next = NULL;
		*stack = second;
	}
}

void	ft_rev_rot_bonus(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		tmp = *stack;
		while (tmp->next)
		{
			last = tmp;
			tmp = tmp->next;
		}
	}
	last->next = NULL;
	ft_add_front_b(stack, tmp);
}
void	ft_swap_bonus(t_stack **stack)
{
	int	tmp;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
	}
}