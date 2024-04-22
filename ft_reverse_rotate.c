/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:37:39 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/22 12:02:00 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	ft_lstadd_front(&*stack, tmp);
	ft_printf("rra\n");
}

void	ft_rrb(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	ft_lstadd_front(&*stack, tmp);
	ft_printf("rrb\n");
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
	ft_printf("rrr\n");
}
