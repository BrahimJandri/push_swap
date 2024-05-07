/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:51:54 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/07 15:49:51 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_arry(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_sort_arry(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
				ft_swap_arry(&array[i], &array[j]);
			j++;
		}
		i++;
	}
}

static int	*ft_fill_array(t_stack *stack)
{
	int		i;
	int		len;
	int		*array;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	len = ft_stack_len(stack);
	array = (int *)malloc(sizeof(int) * (len));
	if (!array)
		return (NULL);
	while (tmp)
	{
		array[i++] = tmp->content;
		tmp = tmp->next;
	}
	return (array);
}

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

static void	ft_first_step(t_stack **stack_a, t_stack **stack_b,
		const int *array)
{
	int		size;
	long	offset;
	long	mid;
	long	start;
	long	end;

	size = (*stack_a)->size;
	if(size <= 10)
		offset = size / 6;
	else if(size <= 100)
		offset = size / 35;
	else if(size <= 500)
		offset = size / 50;
		
	mid = (size / 2) - 1;
	start = mid - offset;
	end = mid + offset;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->content >= array[start]
			&& (*stack_a)->content <= array[end])
		{
			ft_pb(stack_a, stack_b);
			if ((*stack_b) && (*stack_b)->next
				&& ((*stack_b)->content < array[mid]))
				    ft_rb(stack_b, 0);
		}
		if (still_in_range(*stack_a, start, end, array))
			ft_ra(stack_a, 0);
        else
		    ft_update_range(size, &start, &end, offset);
	}
}


static int ft_is_exist(t_stack ** stack_b, int c)
{
	t_stack *tmp = *stack_b;
	
	while (tmp)
	{
		if(tmp->content == c)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void ft_second_step(t_stack **stack_a, t_stack **stack_b, const int *array)
{
    t_stack *max = ft_find_max(*stack_b);
    (*stack_b)->index = current_index(*stack_b, max);
    int median = ft_stack_len(*stack_b) / 2;
    int size = median * 2 - 1;
    
    while ((*stack_b)->content != max->content)
    {
        if((*stack_b)->index >= median)
            ft_rrb(stack_b, 0);
        else
            ft_rb(stack_b, 0);
    }
    ft_pa(stack_b, stack_a);
    size--;
    while (*stack_b != NULL)
    {
        if((*stack_b)->content == array[size])
        {
            ft_pa(stack_b, stack_a);
            size--;
        }
        else
        {
            if(ft_last_stack(*stack_a)->content == max->content)
            {
                ft_pa(stack_b, stack_a);
                ft_ra(stack_a, 0);
            }
            else if(ft_last_stack(*stack_a)->content != max->content && ft_is_exist(stack_b, array[size]))
            {	
                while ((*stack_b)->content != array[size])
                {
                    if((*stack_b)->index >= median)
                        ft_rrb(stack_b, 0);
                    else
                        ft_rb(stack_b, 0);
                }
                ft_pa(stack_b, stack_a);
                size--;
            }
            else
			{
                ft_ra(stack_a, 0);
				size--;	
			}
        }
    }
}

void	ft_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	*array;

	array = ft_fill_array(*stack_a);
	ft_sort_arry(array, (*stack_a)->size);
	ft_first_step(stack_a, stack_b, array);
    ft_second_step(stack_a, stack_b, array);
	free(array);
}
