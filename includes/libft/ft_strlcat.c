/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:18:39 by alermi            #+#    #+#             */
/*   Updated: 2024/10/21 19:36:51 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	src_size;
	size_t	dst_size;
	size_t	i;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	i = 0;
	if (dsize <= dst_size)
		return (src_size + dsize);
	while (src[i] && i < dsize - dst_size - 1)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst [dst_size + i] = '\0';
	return (src_size + dst_size);
}
