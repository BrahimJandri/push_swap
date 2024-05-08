/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:51:54 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/08 12:52:53 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int ft_is_exist(t_stack ** stack_b, int c)
// {
// 	t_stack *tmp = *stack_b;
	
// 	while (tmp)
// 	{
// 		if(tmp->content == c)
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

// static void ft_second_step(t_stack **stack_a, t_stack **stack_b, const int *array)
// {
//     t_stack *max = ft_find_max(*stack_b);
//     (*stack_b)->index = current_index(*stack_b, max);
//     int median = ft_stack_len(*stack_b) / 2;
//     int size = median * 2 - 1;
    
//     while ((*stack_b)->content != max->content)
//     {
//         if((*stack_b)->index >= median)
//             ft_rrb(stack_b, 0);
//         else
//             ft_rb(stack_b, 0);
//     }
//     ft_pa(stack_b, stack_a);
//     size--;
//     while (*stack_b != NULL)
//     {
//         if((*stack_b)->content == array[size])
//         {
//             ft_pa(stack_b, stack_a);
//             size--;
//         }
//         else
//         {
//             if(ft_last_stack(*stack_a)->content == max->content)
//             {
//                 ft_pa(stack_b, stack_a);
//                 ft_ra(stack_a, 0);
//             }
//             else if(ft_last_stack(*stack_a)->content != max->content && ft_is_exist(stack_b, array[size]))
//             {	
//                 while ((*stack_b)->content != array[size])
//                 {
//                     if((*stack_b)->index >= median)
//                         ft_rrb(stack_b, 0);
//                     else if((*stack_b)->index <= median)
//                         ft_rb(stack_b, 0);
//                 }
//                 ft_pa(stack_b, stack_a);
//                 size--;
//             }
//             else
// 			{
//                 ft_ra(stack_a, 0);
// 				size--;	
// 			}
//         }
//     }
// }

void	ft_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	*array;
	t_array array_s;
	
	array = ft_fill_array(*stack_a);
	ft_sort_arry(array, (*stack_a)->size);
	ft_first_step(stack_a, stack_b, array, &array_s);
    // ft_second_step(stack_a, stack_b, array);
	free(array);
}
