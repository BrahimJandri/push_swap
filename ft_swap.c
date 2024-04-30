/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:15:44 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/30 11:58:54 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	int	tmp;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
	}
}

void	ft_sa(t_list **stack, int c)
{
	ft_swap(stack);
	if (!c)
		ft_printf("sa\n");
}

void	ft_sb(t_list **stack, int c)
{
	ft_swap(stack);
	if (!c)
		ft_printf("sb\n");
}

void	ft_ss(t_list **stack_a, t_list **stack_b, int c)
{
	ft_sa(stack_a, 1);
	ft_sb(stack_b, 1);
	if (c)
		ft_printf("ss\n");
}
