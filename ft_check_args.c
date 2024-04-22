/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:56:01 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/22 11:59:19 by bjandri          ###   ########.fr       */
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
		ft_error_msg("Error\n");
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error_msg("Error\n");
		i++;
	}
}

static void	ft_check_doubl(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i] != NULL)
	{
		j = i + 1;
		while (str[j] != NULL)
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				ft_error_msg("Error\n");
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

static void	ft_check_empty(char *str)
{
	int	i;
	int	len;

	i = 0;
	if (!str)
	{
		ft_error_msg("Error\n");
	}
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
			break ;
	}
	if (i == len)
		ft_error_msg("Error\n");
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
		ft_error_msg("Memory allocation failed\n");
	ft_check_doubl(str);
	free(string);
	i = 1;
	while (i < ac)
	{
		ft_check_empty(str[i]);
		ft_check_int(str[i]);
		i++;
	}
	a->str = str;
}
