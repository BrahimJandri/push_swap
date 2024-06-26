/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:15:33 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/09 14:35:31 by bjandri          ###   ########.fr       */
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
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_error_msg(char *str)
{
	write(2, str, 6);
	exit(1);
}

void	del(int data)
{
	(void)data;
}

void	free_stack(t_stack **top)
{
	t_stack	*head;

	head = *top;
	while (head != NULL)
	{
		head = head->next;
		free(*top);
		*top = head;
	}
}

int	ft_stack_len(t_stack *stack)
{
	int	size;

	size = 0;
	if (stack == NULL)
		return (-1);
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
