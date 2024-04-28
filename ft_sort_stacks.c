/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 10:24:39 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/28 11:39:43 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_sort_stacks(t_list **stack_a, t_list **stack_b)
{
    int len_stack_a;

    (void)stack_b;
    len_stack_a = ft_stack_len(&stack_a);
    ft_printf("len == %d", len_stack_a);
    return(*stack_a);
}