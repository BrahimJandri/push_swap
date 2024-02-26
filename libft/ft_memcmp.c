/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:15:23 by bjandri           #+#    #+#             */
/*   Updated: 2023/11/22 12:15:24 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char s[] = "hhello worl";
// 	char c[] = "hhllo worll";
// 	printf("%d\n", ft_memcmp(s, c, 3));
// 	printf("%d", memcmp(s, c, 3));

// char *s = NULL;
// char c[] = "hhllo worll";
// printf("%d\n", ft_memcmp(s, c, 3));
// printf("%d", memcmp(s, c, 3));

// char *s = NULL;
// char *c = NULL;
// printf("%d\n", ft_memcmp(s, c, 3));
// printf("%d", memcmp(s, c, 3));
// }
