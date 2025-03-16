/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:47:40 by alermi            #+#    #+#             */
/*   Updated: 2024/10/20 11:02:55 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*c_dest;
	char	*c_src;

	if (!dest && !src)
		return (NULL);
	c_dest = (char *)dest;
	c_src = (char *)src;
	if (c_dest > c_src)
	{
		while (n-- > 0)
			c_dest[n] = c_src[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
