/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:05:01 by alermi            #+#    #+#             */
/*   Updated: 2025/03/09 15:11:10 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft/libft.h"

int	map_wall_control(t_map *map, int x, int y)
{
	while (++x < map->width)
	{
		if (map->map_pattern[0][x] != '1')
			return (0);
	}
	x = -1;
	while (++x < map->width)
	{
		if (map->map_pattern[map->height - 2][x] != '1')
			return (0);
	}
	y = 0;
	while (++y < map->height)
	{
		if (map->map_pattern[y - 1][0] != '1')
			return (0);
	}
	y = 0;
	while (++y < map->height)
	{
		if (map->map_pattern[y - 1][map->width - 1] != '1')
			return (0);
	}
	return (1);
}

void	map_dfs_control(char **visited, int px, int py, t_map *map)
{
	if (visited[py][px] == '1')
		return ;
	else if (visited[py][px] == 'C')
	{
		map->collectables--;
		visited[py][px] = '1';
	}
	else if (visited[py][px] == 'E')
	{
		map->exit--;
		visited[py][px] = '1';
		return ;
	}
	else
		visited[py][px] = '1';
	map_dfs_control(visited, (px + 1), py, map);
	map_dfs_control(visited, px, py + 1, map);
	map_dfs_control(visited, (px - 1), py, map);
	map_dfs_control(visited, px, (py - 1), map);
}

void	map_control(t_map *map)
{
	char	**visited;
	int		i;

	i = 0;
	visited = (char **)ft_calloc(sizeof(char *), map->height);
	if (!visited)
		ft_map_error("Error\nMalloc Error", map);
	if (map->player != 1 || map->exit != 1 || map->collectables <= 0)
	{
		matris_free(visited);
		ft_map_error("\nMap element counts must {P = 1,\n E = 1,\n C != 0}",
			map);
	}
	if (!map_wall_control(map, -1, -1))
		ft_map_error("Error\nMap must be completely surrounded by walls.", map);
	while (i < map->height)
	{
		if (map->map_pattern[i])
			visited[i] = ft_strdup(map->map_pattern[i]);
		i++;
	}
	map_dfs_control(visited, map->player_x, map->player_y, map);
	matris_free(visited);
	if (map->exit != 0 || map->collectables != 0)
		ft_map_error("Error\nMap Dynamic Error", map);
}
