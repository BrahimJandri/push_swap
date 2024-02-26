/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:21:49 by bjandri           #+#    #+#             */
/*   Updated: 2023/11/22 12:21:50 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	ml;

	ml = ft_strlen(str);
	if (c == '\0')
		return (&((char *)str)[ml]);
	while (ml >= 0)
	{
		if (str[ml] == (char)c)
			return (&((char *)str)[ml]);
		ml--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char str[] = "Hello World!";
// 	char c = 'W';
// 	printf("%s", ft_strrchr(str, c));
// }
