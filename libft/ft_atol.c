/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:47:04 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/11 16:10:11 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static size_t	ft_strsize(const char *str)
{
	size_t	i;
	size_t res;
	
	i = 0;
	res = 0;
	while (str[i] == '0' || str[i] == '-' || str[i] == '+')
		i++;
	while (str[i++])
		res++;
	return (res);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	resu;
	char	*s;

	if(ft_strsize(str) >= 12)
		return (LONG_MAX);
	sign = 1;
	resu = 0;
	s = (char *)str;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		resu = resu * 10 + *s - '0';
		s++;
	}
	return (resu * sign);
}
