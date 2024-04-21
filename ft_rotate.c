/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:57:07 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/21 14:37:48 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	stack = stack->next;
	tmp->next = NULL;
	ft_lstadd_back(&stack, tmp);
}

void	ft_rb(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	stack = stack->next;
	tmp->next = NULL;
	ft_lstadd_back(&stack, tmp);
}

void	ft_rotate(t_list *stack_a, t_list *stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}

void	ft_rr(t_list *stack_a, t_list *stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}

void	ft_rra(t_list *stack)
{
	t_list	*tmp;
	t_list	*last;

	tmp = stack;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	ft_lstadd_front(&stack, tmp);
}

void	ft_rrb(t_list *stack)
{
	t_list	*tmp;
	t_list	*last;

	tmp = stack;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	ft_lstadd_front(&stack, tmp);
}

void	ft_reverse_rotate(t_list *stack_a, t_list *stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}

void	ft_rrr(t_list *stack_a, t_list *stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}