/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:26:59 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/09 10:46:26 by bjandri          ###   ########.fr       */
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
	t_stack	stack_b;

	stack_a.head = NULL;
	stack_b.head = NULL;
	if (ac < 2)
		return (0);
	ft_check_args(ac, av, &stack_a);
	stack_a.head = ft_creat_stack(ac, stack_a.str);
	stack_a.size = ft_stack_len(stack_a.head);
	stack_a.head->size = stack_a.size;
	if (!ft_is_sorted(stack_a.head))
	{
		if (ft_stack_len(stack_a.head) <= 3)
			ft_sort_three(&stack_a.head);
		if (ft_stack_len(stack_a.head) == 4)
			ft_sort_four(&stack_a.head, &stack_b.head);
		if (ft_stack_len(stack_a.head) == 5)
			ft_sort_five(&stack_a.head, &stack_b.head);
		else if (ft_stack_len(stack_a.head) > 5)
			ft_sort_stacks(&stack_a.head, &stack_b.head);
	}
	print_stack(&stack_a.head);
	free_stack(&stack_a.head);
	return (0);
}
