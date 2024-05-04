/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:22:39 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/03 17:50:34 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *str, int c, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
void				*ft_calloc(size_t nitems, size_t size);
char				*ft_strjoin(const char *s1, const char *s2);
char				**ft_split(char const *s, char c);
int					ft_printf(const char *format, ...);
int					ft_printf_add(void *ptr);
int					ft_printf_hexlow(unsigned int n);
int					ft_printf_char(int c);
int					ft_printf_hexupp(unsigned int n);
int					ft_printf_int(int n);
int					ft_printf_str(char *str);
int					ft_printf_unsigned(unsigned int n);
size_t				ft_strlen(const char *str);
long				ft_atol(const char *str);

#endif
