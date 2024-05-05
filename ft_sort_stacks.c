/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:51:54 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/05 16:50:57 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void ft_swap_arry(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

static void ft_sort_arry(t_stack *stack, int size)
{
    int i = 0;
    while (i < size - 1)
    {
        int j = i + 1;
        while (j < size)
        {
            if (stack->array[i] > stack->array[j])
                ft_swap_arry(&stack->array[i], &stack->array[j]);
            j++;
        }
        i++;
    }
}


static void ft_fill_array(t_stack *stack)
{
    int i;
    int len;
    t_stack *tmp;
    
    i = 0;
    tmp = stack;
    len = ft_stack_len(stack);
    stack->array = (int *)malloc(sizeof(int) * (len));
    if(!stack->array)
        return ;
    while (tmp)
    {
        stack->array[i++] = tmp->content;
        tmp = tmp->next;
    }
}

void    ft_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
    (void)stack_b;
    ft_fill_array(*stack_a);
    ft_sort_arry(*stack_a, ft_stack_len((*stack_a)->head));
    ft_printf("num1 = %d\n",(*stack_a)->array[0]);
    ft_printf("num2 = %d\n",(*stack_a)->array[1]);
    ft_printf("num3 = %d\n",(*stack_a)->array[2]);
    ft_printf("num4 = %d\n",(*stack_a)->array[3]);
    ft_printf("num5 = %d\n",(*stack_a)->array[4]);


    free((*stack_a)->array);
}
