/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:29:37 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/08 22:44:28 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int ft_index(int nb, int *arr, int len)
{
	int i = 0;
	while (i < len)
	{
		if(arr[i] == nb)
			return i;
		i++;
	}
	return i;	
}

static void initindex(t_stack **stack, int *arr)
{
	int len = ft_stack_len(*stack);
	t_stack *stack_a;
	int i = 0;
	stack_a = *stack;
	while (i < len)
	{
		stack_a->index = ft_index(stack_a->content, arr, len);
		stack_a = stack_a->next;
		i++;
	}
}
static int ma3rt(t_stack *stack_a, int len , int p)
{
	int i = 0;
	while (stack_a)
	{
		if ((stack_a)->index <= len + p)
		{
			return i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return i;
}
void	ft_first_step(t_stack **stack_a, t_stack **stack_b,
 		int *array)
{
	initindex(stack_a , array);
	int i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			ft_pb(stack_a, stack_b);
			ft_rb(stack_b, 0);
			i++;
		}
		else if ((*stack_a)->index <= i + 15)
		{
			ft_pb(stack_a, stack_b);
			i++;
		}
		else if (ma3rt(*stack_a,i , 15) <= ft_stack_len(*stack_a)/ 2)
		{
			ft_ra(stack_a,0);
		}
		else
		{
			ft_rra(stack_a,0);
		}		
	}
}