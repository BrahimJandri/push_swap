/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:26:59 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/22 12:00:26 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list **head)
{
	t_list	*ptr;

	ptr = *head;
	// ft_printf("%d\n", ptr->content);
	// ft_printf("%d\n", ptr->next->content);
	while (ptr != NULL)
	{
		ft_printf("%d\n", ptr->content);
		ptr = ptr->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	a;

	if (ac < 2)
		return (0);
	ft_check_args(ac, av, &a);
	a.top = ft_creat_stack(ac, a.str);
	if (!ft_is_sorted(a.top))
	{
		ft_sort_three(&a.top);
	}
	// print_stack(&a.top);
	free_stack(&a.top);
	return (0);
}
