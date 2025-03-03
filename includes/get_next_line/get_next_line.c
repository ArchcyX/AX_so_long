/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:10:32 by alermi            #+#    #+#             */
/*   Updated: 2024/12/24 14:45:58 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*ft_get_line(int fd, char *data)
{
	ssize_t	byte_size;
	char	*buffer;

	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buffer == NULL)
		return (ft_double_free(data, 0));
	while (1)
	{
		byte_size = read(fd, buffer, BUFFER_SIZE);
		if (byte_size < 0)
			return (ft_double_free(buffer, data));
		if (byte_size == 0)
			break ;
		buffer[byte_size] = '\0';
		data = get_strjoin(data, buffer);
		if (!data)
			return (ft_double_free(data, buffer));
		if (ft_strchr(data, '\n'))
			break ;
	}
	free (buffer);
	return (data);
}

static char	*ft_str_creator(char *data)
{
	int		i;
	char	*str;

	i = -1;
	while (data[++i] != '\n' && data[i] != '\0')
		;
	if (data[i] == '\n')
		i++;
	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (ft_double_free(data, 0));
	i = -1;
	while (data[++i] != '\n' && data[i] != '\0')
		str[i] = data[i];
	if (data[i] == '\n')
		str[i] = '\n';
	return (str);
}

static char	*ft_data_update(char *data)
{
	char	*updated_data;
	size_t	i;
	size_t	j;

	i = -1;
	while (data[++i] != '\n' && data[i] != '\0')
		;
	if (data[i] == '\n')
		i++;
	if (!data[i])
		return (ft_double_free(data, 0));
	updated_data = (char *)ft_calloc(get_strlen(data + i) + 1,
			sizeof(char));
	if (!updated_data)
		return (ft_double_free(data, 0));
	j = 0;
	while (data[i])
		updated_data[j++] = data[i++];
	ft_double_free(data, 0);
	return (updated_data);
}

char	*get_next_line(int fd)
{
	static char	*data = NULL;
	char		*str;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	data = ft_get_line(fd, data);
	if (!data)
		return (NULL);
	str = ft_str_creator(data);
	if (!str)
		return (ft_double_free(data, 0));
	data = ft_data_update(data);
	return (str);
}
