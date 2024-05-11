/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:15:44 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/01 08:52:59 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	int	tmp;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
	}
}

void	ft_sa(t_stack **stack, int c)
{
	ft_swap(stack);
	if (!c)
		ft_printf("sa\n");
}

void	ft_sb(t_stack **stack, int c)
{
	ft_swap(stack);
	if (!c)
		ft_printf("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, int c)
{
	ft_sa(stack_a, 1);
	ft_sb(stack_b, 1);
	if (c)
		ft_printf("ss\n");
}
