/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:25:19 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/23 10:57:10 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(t_list *stack)
{
	t_list	*max;
	t_list	*cur;

	if (!stack)
	{
		return (-1);
	}
	max = stack;
	cur = stack->next;
	while (cur != NULL)
	{
		if (cur->content > max->content)
			max = cur;
		cur = cur->next;
	}
	return (max->content);
}

t_list	*ft_sort_three(t_list **stack)
{
	t_list	*last;
	int		max;

	last = ft_lstlast(*stack);
	max = ft_find_max(*stack);
	while (last->content != max)
	{
		ft_ra(stack);
		last = ft_lstlast(*stack);
	}
	if ((*stack)->content > (*stack)->next->content)
		ft_sa(stack);
	return (*stack);
}
