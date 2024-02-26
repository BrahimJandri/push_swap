/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:14:36 by bjandri           #+#    #+#             */
/*   Updated: 2023/11/22 12:14:37 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		dgt;
	long int	nb;

	nb = n;
	dgt = ft_intlen(n);
	if (n < 0)
	{
		nb *= -1;
		dgt++;
	}
	str = (char *)malloc(sizeof(char) * (dgt + 1));
	if (!str)
		return (NULL);
	str[dgt] = '\0';
	while (dgt--)
	{
		str[dgt] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

// #include <stdio.h>

// int main()
// {
// 	int a = -2147483648;
// 	int b = 2147483647;
// 	int c = 2147483649;
// 	int d = 2147483650;
// 	printf("%s\n", ft_itoa(a));
// 	printf("%s\n", ft_itoa(b));
// 	printf("%s\n", ft_itoa(c));
// 	printf("%s", ft_itoa(d));

// 	return (0);
// }
