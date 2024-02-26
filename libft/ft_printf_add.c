/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:52:31 by bjandri           #+#    #+#             */
/*   Updated: 2024/01/13 17:52:33 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex(unsigned long int n)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789abcdef";
	if (n <= 15)
	{
		i += ft_printf_char(str[n]);
	}
	else if (n >= 16)
	{
		i += hex(n / 16);
		i += ft_printf_char(str[n % 16]);
	}
	return (i);
}

int	ft_printf_add(void *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (ft_printf_str("(nil)"));
	i += ft_printf_str("0x");
	i += hex((unsigned long int)ptr);
	return (i);
}

// int main() {
//     int some_int = 6;
//     int *ptr = &some_int;

//     ft_printf_add(ptr);
//     printf("\n%p\n", (void *)ptr);

//     return (0);
// }
