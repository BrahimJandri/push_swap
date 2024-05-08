/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:29:37 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/08 15:35:36 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_update_range(int size, long *start, long *end, int offset)
{
	*start = *start - offset;
	*end = *end + offset;
	if (*start < 0)
		*start = 0;
	if (*end > (size - 1))
		*end = (size - 1);
}

static bool	still_in_range(t_stack *stack, long start, long end,
		const int *array)
{
	int	check;

	check = 0;
	while (stack)
	{
		if (stack->content >= array[start] && stack->content <= array[end])
			check++;
		stack = stack->next;
	}
	return (check);
}


void	ft_first_step(t_stack **stack_a, t_stack **stack_b,
		const int *array, t_array *array_s)
{
	array_s->size_array = (*stack_a)->size;
	if(array_s->size_array <= 10)
		array_s->offset = array_s->size_array / 5;
	else if(array_s->size_array <= 100)
		array_s->offset = array_s->size_array / 8;
	else if(array_s->size_array <= 500)
		array_s->offset = array_s->size_array / 50;
    array_s->median = (*stack_a)->size / 2;	
	array_s->mid = (array_s->size_array / 2) - 1;
	array_s->start = array_s->mid - array_s->offset;
	array_s->end = array_s->mid + array_s->offset;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->content >= array[array_s->start]
			&& (*stack_a)->content <= array[array_s->end])
		{
			ft_pb(stack_a, stack_b);
			if ((*stack_b) && (*stack_b)->next
				&& ((*stack_b)->content < array[array_s->mid]))
				    ft_rb(stack_b, 0);
		}
		if (still_in_range(*stack_a, array_s->start, array_s->end, array))
        {
            (*stack_a)->index = current_index(*stack_a, *stack_a);
            if((*stack_a)->index <= array_s->median)
			    ft_ra(stack_a, 0);
            else if((*stack_a)->index >= array_s->median)
                ft_rra(stack_a, 0);
        }
        else
		    ft_update_range(array_s->size_array, &array_s->start, &array_s->end, array_s->offset);
	}
}
