/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:26:59 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/21 17:14:58 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int ac, char **av)
{
	t_stack	a;

	ft_check_args(ac, av, &a);
	a.top = ft_creat_stack(ac, a.str);
	ft_sort_three(a.top);
	free_stack(&a.top);
	return (0);
}
