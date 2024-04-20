/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:47:02 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/20 14:22:44 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*node;
	t_list	*ptr;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		ptr = node->next;
		del(node->content);
		free(node);
		node = ptr;
	}
	*lst = NULL;
}

void	del(int data)
{
	(void)data;
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew(10);
	node2 = ft_lstnew(20);
	node3 = ft_lstnew(30);
	node1->next = node2;
	node2->next = node3;
	printf("node1 %d\n", node1->content);
	printf("node2 %d\n", node2->content);
	printf("node3 %d\n", node3->content);
	ft_lstclear(&node1, del);
}
