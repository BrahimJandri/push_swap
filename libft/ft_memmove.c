/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:16:13 by bjandri           #+#    #+#             */
/*   Updated: 2023/11/22 12:16:14 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (!destination && !source)
		return (NULL);
	if (destination == source || size == 0)
		return (destination);
	if (dst > src && src + size > dst)
	{
		dst += size - 1;
		src += size - 1;
		while (size--)
			*dst-- = *src--;
	}
	else
	{
		while (size)
		{
			*dst++ = *src++;
			size--;
		}
	}
	return (destination);
}

// #include <stdio.h>
// #include <string.h>

// int main ()
// {
// char *d = "NULL";
// char *f = (char *)ft_memmove(d ,((void *)0), 5);
// printf("%s", f);

// 	char d[4] = "NULL";
// 	char *f = (char *)ft_memmove(d + 1, d, 3);
// 	printf("%s", f);
// }
