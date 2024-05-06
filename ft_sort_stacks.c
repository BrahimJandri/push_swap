/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:51:54 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/05 23:29:26 by bjandri          ###   ########.fr       */
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

static void ft_update_range(t_stack **stack, int *start, int *end, int offset)
{
    *start -= offset;
    *end += offset;
    if(*start < 0)
        *start = 0;
    if(*end > ((*stack)->size - 1))
        *end =  ((*stack)->size - 1);
}

// static bool in_range(t_stack **stack_a, int start, int end)
// {
//     if((*stack_a)->content >= (*stack_a)->array[start] && (*stack_a)->content <= (*stack_a)->array[end])
//         return (true);
//     return (false);
// }

static bool still_in_range(t_stack **stack, int start, int end)
{
    t_stack *tmp = *stack; 
    while(tmp)
    {
        if (tmp->content <= (*stack)->array[start] && tmp->content >= (*stack)->array[end])
            tmp = tmp->next;
        else
            return 1;
    }
    return (0);
}

static void ft_first_step(t_stack **stack_a, t_stack **stack_b)
{   
    int offset = (*stack_a)->size / 2;
    int mid = (*stack_a)->size / 2 - 1;
    int start = mid - offset;
    int end = mid + offset;

    while (*stack_a != NULL)
    {
        
        if((*stack_a)->content >= (*stack_a)->array[start] && (*stack_a)->content <= (*stack_a)->array[end])
            {
                ft_pb(stack_a, stack_b);
                if((*stack_b) && (*stack_b)->next && ((*stack_b)->content > (*stack_a)->array[mid]))
                    ft_rb(stack_b, 0);
            }
        else if (!still_in_range(stack_a, start, end))
            ft_update_range(stack_a, &start, &end, offset);
        ft_ra(stack_a, 0);
    }    
}

void    ft_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
    (void)stack_b;

    ft_fill_array(*stack_a);
    ft_sort_arry(*stack_a, (*stack_a)->size);
    ft_first_step(stack_a, stack_b);
    free((*stack_a)->array);
}
