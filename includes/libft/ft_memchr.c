/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:05:15 by alermi            #+#    #+#             */
/*   Updated: 2024/10/23 14:05:17 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*tp_s;
	char		tp_c;

	tp_s = (const char *)s;
	tp_c = (char)c;
	while (n--)
	{
		if (*tp_s == tp_c)
			return ((void *)tp_s);
		tp_s++;
	}
	return (NULL);
}
