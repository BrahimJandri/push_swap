/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:15:33 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/22 15:25:27 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_error_msg(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

void	del(int data)
{
	(void)data;
}

void	free_stack(t_list **top)
{
	t_list	*head;

	head = *top;
	while (head != NULL)
	{
		head = head->next;
		free(*top);
		*top = head;
	}
}

int	ft_find_max(t_list *stack)
{
	t_list	*max;
	t_list	*cur;

	max = stack;
	cur = stack->next;
	while (cur != NULL)
	{
		if (cur->content > max->content)
			max = cur;
		cur = cur->next;
	}
	return (max->content);
}

int	ft_find_min(t_list *stack)
{
	t_list	*min;
	t_list	*cur;

	min = stack;
	cur = stack->next;
	while (cur != NULL)
	{
		if (cur->content < min->content)
			min = cur;
		cur = cur->next;
	}
	return (min->content);
}

int	ft_stack_len(t_list *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}