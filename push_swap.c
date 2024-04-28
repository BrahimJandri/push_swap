/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:26:59 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/28 12:05:10 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list **head)
{
	t_list	*ptr;

	ptr = *head;
	while (ptr != NULL)
	{
		ft_printf("%d\n", ptr->content);
		ptr = ptr->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	a.top = NULL;
	b.top = NULL;
	if (ac < 2)
		return (0);
	ft_check_args(ac, av, &a);
	a.top = ft_creat_stack(ac, a.str);
	if (!ft_is_sorted(a.top))
	{
		if (ft_lstsize(a.top) <= 3)
			ft_sort_three(&a.top);
		if (ft_lstsize(a.top) == 4 || ft_lstsize(a.top) == 5)
			ft_sort_five(&a.top, &b.top);
		else
			ft_sort_stacks(&a.top, &b.top);
	}
	// print_stack(&a.top);
	free_stack(&a.top);
	return (0);
}
