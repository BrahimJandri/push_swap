/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:25:38 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/08 11:27:12 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_arry(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_arry(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
				ft_swap_arry(&array[i], &array[j]);
			j++;
		}
		i++;
	}
}

int	*ft_fill_array(t_stack *stack)
{
	int		i;
	int		len;
	int		*array;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	len = ft_stack_len(stack);
	array = (int *)malloc(sizeof(int) * (len));
	if (!array)
		return (NULL);
	while (tmp)
	{
		array[i++] = tmp->content;
		tmp = tmp->next;
	}
	return (array);
}