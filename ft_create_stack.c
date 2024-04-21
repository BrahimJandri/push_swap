/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:58:19 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/21 12:09:36 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_creat_stack(int ac, char **av)
{
	t_list	*head;
	t_list	*new;
	int		i;

	if (ac < 2)
		return (NULL);
	head = ft_lstnew(ft_atoi(av[1]));
	if (!head)
		return (NULL);
	i = 2;
	while (i < ac)
	{
		new = ft_lstnew(ft_atoi(av[i]));
		if (!new)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		i++;
	}
	return (head);
}
