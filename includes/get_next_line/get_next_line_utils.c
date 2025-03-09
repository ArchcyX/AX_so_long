/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:10:09 by alermi            #+#    #+#             */
/*   Updated: 2024/12/24 14:47:34 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_double_free(char *locate1, char *locate2)
{
	if (locate1)
		free(locate1);
	locate1 = NULL;
	if (locate2 != 0)
	{
		free(locate2);
		locate2 = NULL;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char )c)
		return ((char *)s);
	return (NULL);
}

void	*get_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	while (i < nmemb * size)
		tmp[i++] = 0;
	return (tmp);
}

size_t	get_strlen(const char *s)
{
	char	*p;

	if (!s)
		return (0);
	p = (char *)s;
	while (*p)
		p++;
	return ((size_t)(p - s));
}

char	*get_strjoin(char *data, char	*buffer)
{
	size_t	data_len;
	size_t	buf_len;
	size_t	i;
	size_t	j;
	char	*new_data;

	data_len = get_strlen(data);
	buf_len = get_strlen(buffer);
	new_data = (char *)get_calloc((buf_len + data_len + 1), sizeof(char));
	if (!new_data)
		return (ft_double_free(data, 0));
	i = -1;
	while (++i < data_len)
		new_data[i] = data[i];
	j = -1;
	while (++j < buf_len)
		new_data[i++] = buffer[j];
	ft_double_free(data, 0);
	return (new_data);
}
