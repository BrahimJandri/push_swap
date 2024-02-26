/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:16:30 by bjandri           #+#    #+#             */
/*   Updated: 2023/11/22 12:16:32 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*x;
	size_t			i;

	if (n == 0)
		return (str);
	x = (unsigned char *)str;
	i = 0;
	while (i < n)
		x[i++] = c;
	return (str);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// int arry[] = {12,836,83764,83};
// ft_memset(arry, 0, 6);
// for (int i = 0; i < 2; i++)
// 	printf("%d", arry[i]);

// 	char str[] = "hello";
// 	ft_memset(str, 'a', 5);
// 	printf("%s", str);
// }
