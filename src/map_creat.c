/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:50:39 by alermi            #+#    #+#             */
/*   Updated: 2025/03/09 15:10:33 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line/get_next_line.h"
#include "../includes/libft/libft.h"

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	init_map(t_map *map, char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		ft_map_error("Map Error", map);
	calculate_size(map, fd);
	map_creator(map, file_path);
	map_tile_size(map);
	map_control(map);
	map_tile_size(map);
	close(fd);
}

void	map_tile_size(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (map->map_pattern[++y])
	{
		x = -1;
		while (map->map_pattern[y][++x] != '\n')
		{
			if (map->map_pattern[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				map->player++;
			}
			else if (map->map_pattern[y][x] == 'E')
				map->exit++;
			else if (map->map_pattern[y][x] == 'C')
				map->collectables++;
			else if (map->map_pattern[y][x] != '1'
				&& map->map_pattern[y][x] != '0')
				ft_map_error("Invalid Map tile elements", map);
		}
	}
}

void	calculate_size(t_map *map, int fd)
{
	char	*str;

	str = get_next_line(fd);
	if (!str)
		ft_map_error("Map File Error", map);
	map->width = ft_strlen(str) - 1;
	map->height = 1;
	while (str)
	{
		if ((int)(ft_strlen(str) - 1) != map->width)
		{
			free(str);
			close(fd);
			ft_map_error("Map Size Error", map);
		}
		else
		{
			free(str);
			map->height++;
			str = get_next_line(fd);
		}
	}
}

void	map_creator(t_map *map, char *file_path)
{
	int		fd;
	int		counter;
	char	*line;

	map->map_pattern = (char **)malloc(sizeof(char *) * map->height);
	if (!map->map_pattern)
		return (ft_map_error("Malloc Error", map));
	fd = open(file_path, O_RDONLY);
	counter = 0;
	if (fd == -1)
		ft_map_error("Map Error", map);
	line = get_next_line(fd);
	if (!line)
		ft_map_error("Malloc Error", map);
	while (line)
	{
		map->map_pattern[counter] = line;
		line = get_next_line(fd);
		counter++;
	}
	map->map_pattern[counter] = NULL;
	close(fd);
}
