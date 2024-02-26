/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:51:40 by bjandri           #+#    #+#             */
/*   Updated: 2024/01/13 17:51:41 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n <= 9)
	{
		i += ft_printf_char(n + '0');
	}
	else
	{
		i += ft_printf_int(n / 10);
		i += ft_printf_char(n % 10 + '0');
	}
	return (i);
}
