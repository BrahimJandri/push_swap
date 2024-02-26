/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:20:02 by bjandri           #+#    #+#             */
/*   Updated: 2023/11/22 12:20:03 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i + 1 < size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char dest[] = "NULL";
// 	char src[] = "NULL";
// 	printf("%ld", ft_strlcpy(dest, src, 0));

// char dest[] = "NULL";
// char src[] = "NULL";
// printf("%ld", strlcpy(dest, src, 5));
// }
