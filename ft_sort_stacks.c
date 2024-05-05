/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:51:54 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/05 11:17:50 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_array(int *array)
{
    int i = 0;

    while(array[i] != '\0')
    {
        ft_printf("d%\n", array[i]);
        i++;
    }
}

static void ft_fill_array(t_stack *stack)
{
    int i;
    int len;
    int *array;
    
    i = 0;
    len = ft_stack_len(stack);
    array = (int *)malloc(sizeof(int) * (len));
    if(array)
        return ;
    while (stack)
    {
        stack->array[i++] = stack->content;
        stack = stack->next;
    }
}

void    ft_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
    (void)stack_b;
    ft_fill_array(*stack_a);
}
