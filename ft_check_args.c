/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:56:01 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/23 18:15:39 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_int(char *str)
{
	int		i;
	long	tmp;

	tmp = ft_atol(str);
	i = 0;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1]))
		i++;
	if (tmp > 2147483647 || tmp < -2147483648)
	{
		free(str);
		ft_error_msg("Error\n");
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			free(str);
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
	int j;

	i = 0;
	while(++i < ac)
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
	int		i;
	char	**str;
	char	*string;

	i = 1;
	string = ft_join(av);
	str = ft_split(string, ' ');
	if (!str)
	{
		ft_free_str(str);
		ft_error_msg("Memory allocation failed\n");
	}
	ft_check_empty(ac, av);
	ft_check_doubl(str);
	while (str[i])
	{
		ft_check_int(str[i]);
		i++;
	}
	free(string);
	a->str = str;
}
