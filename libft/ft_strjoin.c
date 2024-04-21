/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:19:22 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/21 08:41:10 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;

	if (!s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	if (s2 != NULL)
		ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free((char *)s1);
	return (str);
}
