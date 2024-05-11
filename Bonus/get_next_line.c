/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:08:43 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/11 09:52:20 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_first_line(int fd, char *str)
{
	char	*buf;
	int		ret;

	buf = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buf)
		return (NULL);
	ret = 1;
	while (ret != 0 && !ft_strchr(str, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[ret] = '\0';
		str = ft_strjjoin(str, buf);
		if (!str)
			return (NULL);
	}
	free(buf);
	return (str);
}

char	*ft_next_line(char *str)
{
	char	*next_line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	next_line = malloc(sizeof(char) * (i + 2));
	if (!next_line)
	{
		free(next_line);
		return (NULL);
	}
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		next_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		next_line[i++] = '\n';
	next_line[i] = '\0';
	return (next_line);
}

char	*ft_new_str(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	while (str[i])
		i++;
	if (!str[i])
		return (ft_free(str));
	new_str = malloc(sizeof(char) * (ft_strllen(str) - i + 1));
	if (!new_str)
		return (ft_free(str));
	i++;
	j = 0;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_first_line(fd, str);
	if (!str)
		return (NULL);
	next_line = ft_next_line(str);
	str = ft_new_str(str);
	if (next_line[0] == '\0')
	{
		free(next_line);
		next_line = NULL;
	}
	return (next_line);
}