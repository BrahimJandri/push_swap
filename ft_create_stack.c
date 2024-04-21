/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:58:19 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/21 19:25:12 by bjandri          ###   ########.fr       */
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

	i = 2;
	head = ft_lstnew(ft_atoi(av[1]));
	
	if (!head)
		return (NULL);
	while (av[i] != NULL)
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
	ft_free_str(av);
	return (head);
}
