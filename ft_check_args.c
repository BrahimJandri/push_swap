/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:56:01 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/21 11:39:48 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_int(char *str)
{
	int	i;
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
				ft_error_msg("Error\n");
			j++;
		}
		i++;
	}
}
static char *ft_join(char **str)
{
	int i;
	char *string;
	
	i = 0;
	string = NULL;
	while(str[i])
	{
		string = ft_strjoin(string, str[i]);
		string = ft_strjoin(string, " ");
		i++;
	}
	return(string);
}

static void	ft_check_empty(char *str)
{
	int i;
	int len;

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
            break;
	}
	if(i == len)
		ft_error_msg("Error\n");
}


void	ft_check_args(int ac, char **av)
{
	int		i;
	char	**str;
	char *string;
	
	i = 1;
	ft_check_doubl(ac, av);
	string = ft_join(av);
	str = ft_split(string, ' ');
	free(string);
	if (!str)
		ft_error_msg("Memory allocation failed\n");
	while (i < ac)
	{
		ft_check_empty(str[i]);
		ft_check_int(str[i]);
		i++;
	}
	ft_free_str(str);
}
