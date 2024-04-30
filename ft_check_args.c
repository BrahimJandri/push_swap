/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:56:01 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/30 11:49:40 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_int(int ac, char **av)
{
	int		i;
	int		j;
	long	tmp;

	i = 1;
	while (i < ac)
	{
		j = 0;
		tmp = ft_atol(av[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			ft_error_msg("Error\n");
		while (av[i][j])
		{
			if ((av[i][j] == '-' || av[i][j] == '+') && (av[i][j + 1]))
				j++;
			if (((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == ' '))
				j++;
			else
				ft_error_msg("Error\n");
		}
		i++;
	}
}

static void	ft_check_doubl(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
			{
				ft_free_str(str);
				ft_error_msg("Error\n");
			}
			j++;
		}
		i++;
	}
}

static char	*ft_join(char **str)
{
	int		i;
	char	*string;

	i = 0;
	string = NULL;
	while (str[i])
	{
		string = ft_strjoin(string, str[i]);
		string = ft_strjoin(string, " ");
		i++;
	}
	return (string);
}

static void	ft_check_empty(int ac, char **av)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		len = ft_strlen(av[i]);
		while (av[j])
		{
			if (av[i][j] == ' ')
				j++;
			else
				break ;
		}
		if (j == len)
			ft_error_msg("Error\n");
	}
}

void	ft_check_args(int ac, char **av, t_stack *a)
{
	char	**str;
	char	*string;

	ft_check_int(ac, av);
	ft_check_empty(ac, av);
	string = ft_join(av);
	str = ft_split(string, ' ');
	free(string);
	if (!str)
	{
		ft_free_str(str);
		ft_error_msg("Memory allocation failed\n");
	}
	ft_check_doubl(str);
	a->str = str;
}
