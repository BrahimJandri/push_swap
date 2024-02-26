/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:54:20 by bjandri           #+#    #+#             */
/*   Updated: 2024/02/15 12:08:23 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkers(const char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'd' || c == 'i')
		i += ft_printf_int(va_arg(args, int));
	else if (c == 's')
		i += ft_printf_str(va_arg(args, char *));
	else if (c == 'c')
		i += ft_printf_char(va_arg(args, int));
	else if (c == 'X')
		i += ft_printf_hexupp(va_arg(args, unsigned int));
	else if (c == 'x')
		i += ft_printf_hexlow(va_arg(args, unsigned int));
	else if (c == 'p')
		i += ft_printf_add(va_arg(args, void *));
	else if (c == 'u')
		i += ft_printf_unsigned(va_arg(args, unsigned int));
	else
		i += ft_printf_char(c);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	if (!format || (*(format) == '%' && *(format + 1) == '\0'))
		return (-1);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '%')
		{
			i += ft_printf_char(*format);
			format++;
		}
		else if (*format == '%')
		{
			format++;
			i += ft_checkers(*format, args);
		}
		else
			i += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (i);
}
