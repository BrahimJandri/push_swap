/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:12:11 by bjandri           #+#    #+#             */
/*   Updated: 2023/11/22 12:12:17 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	resu;
	char	*s;

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

// #include <stdio.h>

// int main()
// {
// 	char a[] = " 	\n \t -2147483649";
// 	char b[] = " 	2147483647lkjds";
// 	char c[] = "snckj28899    \n";
// 	char d[] = "             492-384dssdsnckj28899    \n";
// 	char e[] = "             2147483649-384dssdsnckj28899    \n";

// 	printf("%d\n", ft_atoi(a));
// 	printf("%d\n", ft_atoi(b));
// 	printf("%d\n", ft_atoi(c));
// 	printf("%d\n", ft_atoi(d));
// 	printf("%d\n", ft_atoi(e));

// 	return (0);
// }
