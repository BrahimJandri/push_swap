/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:15:01 by bjandri           #+#    #+#             */
/*   Updated: 2023/11/22 12:15:03 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	// int s[] = {1,2,3,4,5,6};
// 	// ft_memchr(s, 4, 64);
// 	int d = 6;
// 	int *s = &d;

// 	printf("\n%d", *s);
// 		for (size_t i = 0; i < 24; i++)
// 			printf("%d", *(int *)ft_memchr(s, 4, 64));
// }
