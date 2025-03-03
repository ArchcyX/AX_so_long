/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:21:32 by alermi            #+#    #+#             */
/*   Updated: 2024/10/30 11:21:34 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	length;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && *s2)
		return (ft_strdup(s2));
	if (!s2 && *s1)
		return (ft_strdup(s1));
	length = (ft_strlen(s1) + ft_strlen(s2) + 1);
	dest = ft_calloc(sizeof(char), length);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, length);
	ft_strlcat(dest, s2, length);
	return (dest);
}
