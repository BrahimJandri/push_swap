/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_func_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:44:14 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/10 16:25:26 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_str_b(char **str)
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

void	ft_error_msg_b(char *str)
{
	write(2, str, 6);
	exit(1);
}

void	del_b(int data)
{
	(void)data;
}

void	free_stack_b(t_stack **top)
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

int	ft_stack_len_b(t_stack *stack)
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