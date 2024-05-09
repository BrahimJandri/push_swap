/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:29:37 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/09 11:45:46 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_index(int nb, int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == nb)
			return (i);
		i++;
	}
	return (i);
}

static void	initindex(t_stack **stack, int *arr)
{
	int		len;
	t_stack	*stack_a;
	int		i;

	len = ft_stack_len(*stack);
	i = 0;
	stack_a = *stack;
	while (i < len)
	{
		stack_a->index = ft_index(stack_a->content, arr, len);
		stack_a = stack_a->next;
		i++;
	}
}

static int	ft_stil_in_index(t_stack *stack_a, int len, int p)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if ((stack_a)->index <= len + p)
		{
			return (i);
		}
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

static int	ft_check_len(int size)
{
	if (size <= 10)
		return (5);
	else if (size <= 100)
		return (15);
	else
		return (30);
}

void	ft_first_step(t_stack **stack_a, t_stack **stack_b, int *array)
{
	int	p;
	int	i;

	initindex(stack_a, array);
	i = 0;
	p = ft_check_len(ft_stack_len(*stack_a));
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			ft_pb(stack_a, stack_b);
			ft_rb(stack_b, 0);
			i++;
		}
		else if ((*stack_a)->index <= i + p)
		{
			ft_pb(stack_a, stack_b);
			i++;
		}
		else if (ft_stil_in_index(*stack_a, i, p) <= ft_stack_len(*stack_a) / 2)
			ft_ra(stack_a, 0);
		else
			ft_rra(stack_a, 0);
	}
}
