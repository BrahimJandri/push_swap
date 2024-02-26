/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:19:44 by bjandri           #+#    #+#             */
/*   Updated: 2023/11/22 12:19:46 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (dst == NULL && size == 0)
		return (srclen);
	dstlen = ft_strlen(dst);
	j = dstlen;
	if (size == 0 || size <= dstlen)
		return (srclen + size);
	while (src[i] && i < size - dstlen - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (dstlen + srclen);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char *dest = NULL;
// 	char src[] = "NULL";
// 	printf("%ld\n", ft_strlcat(dest, src, 2));
//     printf("%ld", strlcat(dest, src, 2));
// }
