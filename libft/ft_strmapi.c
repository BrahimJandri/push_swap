/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:20:19 by bjandri           #+#    #+#             */
/*   Updated: 2023/11/22 12:20:21 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>

// char	ft_char_convert(unsigned int index, char ch)
// {
//     if (ch >= 'a' && ch <= 'z')
//         return (ch - 32);

//     return (ch);
// }

// int	main(void)
// {
//     char const	input_string[] = "Hello, World!";
//     char		*result_string;

//     result_string = ft_strmapi(input_string, ft_char_convert);

//     printf("Original string: %s\n", input_string);
//     printf("Modified string: %s\n", result_string);

//     free(result_string);
//     return (0);
// }
