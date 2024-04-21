/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:55:42 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/21 14:38:38 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;

	tmp = stack_b;
	stack_b = stack_b->next;
	tmp->next = stack_a;
	stack_a = tmp;
}

void	ft_pb(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;

	tmp = stack_a;
	stack_a = stack_a->next;
	tmp->next = stack_b;
	stack_b = tmp;
}

void	ft_push(t_list *stack_a, t_list *stack_b)
{
	ft_pa(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
}
