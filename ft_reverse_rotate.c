/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:37:39 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/07 12:20:33 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rot(t_stack **stack)
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
	ft_add_front(stack, tmp);
}

void	ft_rra(t_stack **stack, int c)
{
	ft_rev_rot(stack);
	if (!c)
		ft_printf("rra\n");
}

void	ft_rrb(t_stack **stack, int c)
{
	ft_rev_rot(stack);
	if (!c)
		ft_printf("rrb\n");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int c)
{
	ft_rra(stack_a, 1);
	ft_rrb(stack_b, 1);
	if (c)
		ft_printf("rrr\n");
}
