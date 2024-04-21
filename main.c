/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:26:59 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/21 12:08:26 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void print_stack(t_list *stack)
{
    t_list *current = stack;
    while (current != NULL)
	{
        ft_printf("%d\n", current->content);
        current = current->next;
    }
}


int	main(int ac, char **av)
{
	t_stack a;
	// t_stack	*b;
	
	
	ft_check_args(ac, av);
	
	a.top = ft_creat_stack(ac, av);
	print_stack(a.top);
	return (0);
}
