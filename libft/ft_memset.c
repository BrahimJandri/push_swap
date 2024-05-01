/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:16:30 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/01 16:28:23 by bjandri          ###   ########.fr       */
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