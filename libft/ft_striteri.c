/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:19:07 by bjandri           #+#    #+#             */
/*   Updated: 2023/11/22 12:19:08 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>

// void    f(unsigned int i, char *str)
// {
//     if (i % 2 != 0)
//         *str -= 32;
//     else
//         *str += 32;
// }

// int    main(void)
// {
//     char str[] = "HeLlO";
//     ft_striteri(str, f);
//     printf("%s", str);
//     return (0);
// }
