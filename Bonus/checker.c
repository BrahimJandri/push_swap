/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:45:29 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/11 11:01:08 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_is_sorted_b(t_stack *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static t_stack	*ft_creat_stack_b(int ac, char **av)
{
	t_stack	*head;
	t_stack	*new;
	int		i;

	if (ac < 2)
		return (NULL);
	i = 2;
	head = ft_new_stack_b(ft_atoi(av[1]));
	if (!head)
		return (NULL);
	while (av[i] != NULL)
	{
		new = ft_new_stack_b(ft_atoi(av[i]));
		if (!new)
		{
			ft_clear_stack_b(&head, del_b);
			return (NULL);
		}
		ft_add_back_b(&head, new);
		i++;
	}
	ft_free_str_b(av);
	return (head);
}
void ft_exit(char *str)
{
	free(str);
	write(2, "Error\n", 6);
	exit(0);
}

int	main(int ac, char **av)
{
	t_stack stack_a;
    t_stack stack_b;

	stack_a.head = NULL;
	stack_b.head = NULL;
	if (ac < 2)
		return(0);
	ft_check_args_bonus(ac, av, &stack_a);
	stack_a.head = ft_creat_stack_b(ac, stack_a.str);
	check_moves(&stack_a.head, &stack_b.head);
	if(ft_is_sorted_b(stack_a.head))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack_b(&stack_a.head);
}
