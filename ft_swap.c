/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:15:44 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/17 18:10:40 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list *stack)
{
	int	tmp;

	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

void	ft_sb(t_list *stack)
{
	int	tmp;

	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

void	ft_swap(t_list *stack_a, t_list *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}
