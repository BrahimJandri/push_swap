/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:18:58 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/11 10:54:22 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int ft_check_command(char *str)
{
    if (!ft_strncmp("ra\n", str, 3))
		return (1);
	else if (!ft_strncmp("rb\n", str, 3))
		return (2);
	else if (!ft_strncmp("rr\n", str, 3))
		return (3);
	else if (!ft_strncmp("sa\n", str, 3))
		return (4);
	else if (!ft_strncmp("sb\n", str, 3))
		return (5);
	else if (!ft_strncmp("ss\n", str, 3))
		return (6);
	else if (!ft_strncmp("pa\n", str, 3))
		return (7);
	else if (!ft_strncmp("pb\n", str, 3))
		return (8);
	else if (!ft_strncmp("rrb\n", str, 4))
		return (9);
	else if (!ft_strncmp("rra\n", str, 4))
		return (10);
	else if (!ft_strncmp("rrr\n", str, 4))
		return (11);
	return (0);
}
static void ft_two(t_stack **stack_a, t_stack **stack_b, char c)
{
    if (c == 'a')
    {
        ft_rotate_bonus(stack_a);
        ft_rotate_bonus(stack_b);
    }
    else if (c == 'b')
    {
        ft_swap_bonus(stack_a);
        ft_swap_bonus(stack_b);
    }
    else
    {
        ft_rev_rot_bonus(stack_a);
        ft_rev_rot_bonus(stack_b);
    }
}

static void	run_commands(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strncmp("ra\n", str, 3))
		ft_rotate_bonus(stack_a);
	else if (!ft_strncmp("rb\n", str, 3))
		ft_rotate_bonus(stack_b);
	else if (!ft_strncmp("rr\n", str, 3))
		ft_two(stack_a, stack_b, 'a');
	else if (!ft_strncmp("sa\n", str, 3))
		ft_swap_bonus(stack_a);
	else if (!ft_strncmp("sb\n", str, 3))
		ft_swap_bonus(stack_b);
	else if (!ft_strncmp("ss\n", str, 3))
		ft_two(stack_a, stack_b, 'b');
	else if (!ft_strncmp("pa\n", str, 3))
		ft_push_bonus(stack_b, stack_a);
	else if (!ft_strncmp("pb\n", str, 3))
		ft_push_bonus(stack_a, stack_b);
	else if (!ft_strncmp("rrb\n", str, 4))
		ft_rev_rot_bonus(stack_b);
	else if (!ft_strncmp("rra\n", str, 4))
		ft_rev_rot_bonus(stack_a);
	else if (!ft_strncmp("rrr\n", str, 4))
		ft_two(stack_a, stack_b, 'c');

}

void check_moves(t_stack **stack_a, t_stack **stack_b)
{
    char *str;
    
    str = get_next_line(0);
    while (str)
    {
        if(!ft_check_command(str))
            ft_exit(str);
        run_commands(stack_a, stack_b, str);
		free(str);
		str = get_next_line(0);
    }
	free(str);
    return ;
}