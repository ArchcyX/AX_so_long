/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:13:51 by alermi            #+#    #+#             */
/*   Updated: 2024/10/19 17:25:57 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str;
	char	*source;

	source = (char *)src;
	str = (char *)dest;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
		return (ft_memmove(dest, src, n));
	while (n > 0)
	{
		*(str)++ = *(source)++;
		n--;
	}
	return (dest);
}
