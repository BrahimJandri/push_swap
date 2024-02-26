/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:59 by bjandri           #+#    #+#             */
/*   Updated: 2023/11/22 12:14:00 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;
	size_t	n;

	n = nitems * size;
	if (nitems > 0 && SIZE_MAX / nitems < size)
		return (NULL);
	ptr = malloc(n);
	if (!ptr)
		return (NULL);
	if (ptr != NULL)
		ft_bzero(ptr, n);
	return (ptr);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main()
// {
//     size_t n = 0;
//     if(ft_calloc(n,sizeof(size_t)) == NULL)
//       printf("calloc return (NULL"));
//     else
//       printf("zero byte alocated");
//     return (0);
// }
