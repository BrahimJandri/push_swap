/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:26:59 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/17 15:14:19 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *stack)
{
    if (stack && stack->head && stack->head->next)
    {
        void *tmp = stack->head->content;
        stack->head->content = stack->head->next->content;
        stack->head->next->content = tmp;
    }
}

int main(int ac, char **av)
{
    
    if(ac < 2)
        ft_printf("error");
    if(ac < 4)
    {
        
    }
}