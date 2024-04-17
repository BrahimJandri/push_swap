/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:58:19 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/17 14:58:45 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void creat_stack(int ac, char **av)
{
    int i;

    i = 2;
    t_list *head;
    t_list *new;
    
    head = ft_lstnew(av[1]);
    while(i < ac - 1)
    {
        new = ft_lstnew(av[i]);
        ft_lstadd_back(&head, new);
        i++;
    }
}