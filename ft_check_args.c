/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:56:01 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/18 10:51:13 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contain(int nb, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == nb)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
static  void	error_message(char *msg)
{
	(void)msg;
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static int	ft_isnumber(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		i++;
	}
	if ((num[0] == '-' || num[0] == '+') && !num[1])
	{
		return (0);
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static char	**argument(char *av)
{
	char	**args;

	args = ft_split(av, ' ');
	return (args);
}

static  void	free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}

void	ft_check_args(int ac, char **av)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 1;
	if (ac == 2)
		args = argument(av[1]);
	else
		args = av;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnumber(args[i]))
			error_message("Error");
		if (ft_contain(tmp, args, i) == 1)
			error_message("Error");
		if (tmp < INT_MIN || tmp > 2147483647)
			error_message("Error");
		i++;
	}
	if (ac == 2)
		free_string(args);
}