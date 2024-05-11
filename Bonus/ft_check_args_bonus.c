/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:37:36 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/10 16:29:00 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_check_int_b(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (((av[i][j] >= '0' && av[i][j] <= '9') && ((av[i][j + 1] == '-'
							|| av[i][j + 1] == '+')) && (av[i][j + 2] >= '0'
						&& av[i][j + 2] <= '9')))
				ft_error_msg_b("Error\n");
			if ((av[i][j] == '-' || av[i][j] == '+') && (av[i][j + 1] == 32))
				ft_error_msg_b("Error\n");
			if ((av[i][j] == '-' || av[i][j] == '+') && (av[i][j + 1]))
				j++;
			if (((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == ' '))
				j++;
			else
				ft_error_msg_b("Error\n");
		}
		i++;
	}
}

static void	ft_check_doubl_b(char **str)
{
	int	i;
	int	j;
	long tmp;
	
	i = 1;
	while (str[i])
	{
		tmp = ft_atol(str[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			ft_error_msg_b("Error\n");
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
			{
				ft_free_str_b(str);
				ft_error_msg_b("Error\n");
			}
			j++;
		}
		i++;
	}
}

static char	*ft_join_b(char **str)
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

static void	ft_check_empty_b(int ac, char **av)
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
			ft_error_msg_b("Error\n");
	}
}

void	ft_check_args_bonus(int ac, char **av, t_stack *a)
{
	char **str;
	char *string;

	ft_check_int_b(ac, av);
	ft_check_empty_b(ac, av);
	string = ft_join_b(av);
	str = ft_split(string, ' ');
	free(string);
	if (!str)
	{
		ft_free_str_b(str);
		ft_error_msg_b("Memory allocation failed\n");
	}
	ft_check_doubl_b(str);
	a->str = str;
}