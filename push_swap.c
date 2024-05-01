/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:26:59 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/01 16:52:20 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack **head)
{
	t_stack	*ptr;

	ptr = *head;
	while (ptr != NULL)
	{
		ft_printf("%d\n", ptr->content);
		ptr = ptr->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	// t_stack	stack_b;

	stack_a.head = NULL;
	// stack_b.head = NULL;
	if (ac < 2)
		return (0);
	ft_check_args(ac, av, &stack_a);
	stack_a.head = ft_creat_stack(ac, stack_a.str);
	if (!ft_is_sorted(stack_a.head))
	{
		if (ft_stack_len(stack_a.head) == 2)
			ft_sa(&stack_a.head, 0);
		if (ft_stack_len(stack_a.head) == 3)
			ft_sort_three(&stack_a.head);
	}
	print_stack(&stack_a.head);
	free_stack(&stack_a.head);
	return (0);
}
