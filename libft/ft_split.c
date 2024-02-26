/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:18:05 by bjandri           #+#    #+#             */
/*   Updated: 2023/11/22 12:18:12 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			counter++;
			while (*s && *s != c)
				s++;
		}
	}
	return (counter);
}

static void	ft_words_make(char *word, const char *s, size_t j, size_t word_len)
{
	size_t	i;

	i = 0;
	while (word_len)
	{
		word[i] = s[j - word_len];
		i++;
		word_len--;
	}
	word[i] = '\0';
}

static void	*free_str(char **result, size_t i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
	return (NULL);
}

static char	**ft_words_split(char **result, char const *s, char c,
		size_t word_count)
{
	size_t	i;
	size_t	j;
	size_t	word_len;

	i = 0;
	j = 0;
	word_len = 0;
	while (s[j] && i < word_count)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			word_len++;
		}
		result[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!result[i])
			(free_str(result, i));
		ft_words_make(result[i], s, j, word_len);
		word_len = 0;
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_counter;
	char	**result;

	if (s == NULL)
		return (NULL);
	word_counter = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_counter + 1));
	if (!result)
		return (NULL);
	result = ft_words_split(result, s, c, word_counter);
	return (result);
}

// #include <stdio.h>

// int main()
// {
//     char **result = ft_split("hello world split me please ", ' ');

//     for (int i = 0; result[i] != NULL; ++i)
// 	{
//         printf("Token %d: \n%s\n", i + 1, result[i]);
// 		free(result[i]);
//     }
// 	free(result);
// 		return (0);
// }
