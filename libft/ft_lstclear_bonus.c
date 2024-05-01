/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:47:02 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/01 09:02:21 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
