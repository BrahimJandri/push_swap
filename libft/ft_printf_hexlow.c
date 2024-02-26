/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexlow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:53:29 by bjandri           #+#    #+#             */
/*   Updated: 2024/01/13 17:53:31 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_hexlow(unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789abcdef";
	if (n < 16)
	{
		i += ft_printf_char(str[n]);
	}
	else if (n >= 16)
	{
		i += ft_printf_hexlow(n / 16);
		i += ft_printf_char(str[n % 16]);
	}
	return (i);
}
