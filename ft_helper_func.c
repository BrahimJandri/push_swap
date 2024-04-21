/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:15:33 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/21 14:18:17 by bjandri          ###   ########.fr       */
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

void print_stack(t_list *stack)
{
    t_list *current = stack;
    while (current != NULL)
	{
        ft_printf("%d\n", current->content);
        current = current->next;
    }
    t_list *max = ft_find_max(stack);
    ft_printf("max: %d\n", max->content); 
}

t_list *ft_find_max(t_list *stack)
{
    t_list *max = stack;
    t_list *cur = stack->next;

    while (cur != NULL)
	{
        if (cur->content > max->content)
            max = cur;
        cur = cur->next;
    }
    return max;
}

