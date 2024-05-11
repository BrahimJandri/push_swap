/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:58:19 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/01 09:05:11 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_creat_stack(int ac, char **av)
{
	t_stack	*head;
	t_stack	*new;
	int		i;

	if (ac < 2)
		return (NULL);
	i = 2;
	head = ft_new_stack(ft_atoi(av[1]));
	if (!head)
		return (NULL);
	while (av[i] != NULL)
	{
		new = ft_new_stack(ft_atoi(av[i]));
		if (!new)
		{
			ft_clear_stack(&head, del);
			return (NULL);
		}
		ft_add_back(&head, new);
		i++;
	}
	ft_free_str(av);
	return (head);
}
