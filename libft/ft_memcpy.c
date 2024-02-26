/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:15:56 by bjandri           #+#    #+#             */
/*   Updated: 2023/11/22 12:15:58 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*c;
	size_t			i;

	d = (unsigned char *)dest;
	c = (unsigned char *)src;
	i = 0;
	if (dest != src)
	{
		while (i < n)
		{
			d[i] = c[i];
			i++;
		}
	}
	return ((void *)d);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// char s[] = "hhello worl";
// char c[] = "hhllo worll";
// printf("%p\n", ft_memcpy(s, c, 3));
// printf("%p", memcpy(s, c, 3));

// char *s = NULL;
// char c[] = "hhllo worll";
// printf("%p\n", ft_memcpy(s, c, 3));
// printf("%p", memcpy(s, c, 3));

// char s[] = "hhllo worll";
// char c[] = "hhllo worll";
// printf("%p\n", ft_memcpy(s, c, 3));
// printf("%p", memcpy(s, c, 3));
// }
