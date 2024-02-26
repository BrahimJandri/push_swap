/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexupp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:53:03 by bjandri           #+#    #+#             */
/*   Updated: 2024/01/13 17:53:04 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_hexupp(unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789ABCDEF";
	if (n < 16)
	{
		i += ft_printf_char(str[n]);
	}
	else if (n >= 16)
	{
		i += ft_printf_hexupp(n / 16);
		i += ft_printf_char(str[n % 16]);
	}
	return (i);
}
