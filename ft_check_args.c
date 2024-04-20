/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:56:01 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/20 14:18:53 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error_msg("Error is not number\n");
		i++;
	}
}

static void	ft_check_int(char *str)
{
	long	tmp;

	tmp = ft_atol(str);
	if (tmp > 2147483647 || tmp < -2147483648)
		ft_error_msg("Error max or min\n");
}

static void	ft_check_doubl(int len, char **str)
{
	int	i;
	int	j;

	i = 1;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				ft_error_msg("Error double\n");
			j++;
		}
		i++;
	}
}

static void	ft_check_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			ft_error_msg("Error empty arg\n");
		i++;
	}
}

void	ft_check_args(int ac, char **av)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	ft_check_doubl(ac, av);
	while (i < ac)
	{
		str = ft_split(av[i], ' ');
		if (!str)
			ft_error_msg("Memory allocation failed\n");
		j = 0;
		while (str[j])
		{
			ft_isnumber(str[j]);
			ft_check_empty(str[j]);
			ft_check_int(str[j]);
			j++;
		}
		ft_free_str(str);
		i++;
	}
}
