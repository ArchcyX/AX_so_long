/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:50:39 by alermi            #+#    #+#             */
/*   Updated: 2025/03/05 13:51:54 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft/libft.h"
#include "../includes/libft/libft.h"
#include <stdio.h>

void	init_map(t_map *map, char *file_path)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		ft_error("Map Error", map);
	calculate_size(map, fd);
	map_creator(map, file_path);
	map_tile_size(map);
	map_control(map);
	matris_free(map->map_pattern);
	close(fd);
}

void    map_tile_size(t_map *map)
{
    int i;
    int j;

    i = -1;
    while (map->map_pattern[++i])
    {
        j = -1;
        while (map->map_pattern[i][++j] != '\n')
        {
            if (map->map_pattern[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
                map->player++;
			}
			else if (map->map_pattern[i][j] == 'E')
                map->exit++;
            else if (map->map_pattern[i][j] == 'C')
                map->collectables++;
			else if (map->map_pattern[i][j] != '1' && map->map_pattern[i][j] != '0')
					ft_error("Invalid Map tile elements", map);
		}
    }
}

void	calculate_size(t_map *map, int fd)
{
	char	*str;

	str = get_next_line(fd);
	if (!str)
	{
		free(str);
		ft_error("Map File Error", map);
	}
	map->width = ft_strlen(str) - 1;
	map->height = 1;
	while (str)
	{
		if ((ft_strlen(str) - 1) != map->width)
		{
			free(str);
			close(fd);
			ft_error("Map Size Error", map);
		}
		else
		{
			free(str);
			map->height++;
			str = get_next_line(fd);
		}
	}
}


// EDIT THIS CODE = input add fd and delete strings
void	map_creator(t_map *map, char *file_path)
{
	int		fd;
	int		counter;
	char	*line;

	map->map_pattern = (char **)malloc(sizeof(char *) * map->height);
	if (!map->map_pattern)
		return (ft_error("Malloc Error", map));
	fd = open(file_path, O_RDONLY);
	counter = 0;
	if (fd == -1)
		ft_error("Map Error", map);
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		ft_error("Malloc Error", map);
	}
	while (line)
	{
		map->map_pattern[counter] = line;
		line = get_next_line(fd);
		counter++;
	}
	map->map_pattern[counter] = NULL;
	close(fd);
}
