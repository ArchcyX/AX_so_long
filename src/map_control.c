#include "../includes/so_long.h"
#include "../includes/get_next_line/get_next_line.h"
#include <stdio.h>

int map_wall_control(t_map *map, int x, int y)
{
    while (++x < map->width)
    {
        if (map->map_pattern[0][x] != '1')
            return 0;
    }
    x = -1;
    while (++x < map->width)
    {
        if (map->map_pattern[map->height - 2][x] != '1')
            return 0;
    }
    y = 0;
    while (++y < map->height)
    {
        if (map->map_pattern[y - 1][0] != '1')
            return 0;
    }
    y = 0;
    while (++y < map->height)
    {
        if (map->map_pattern[y - 1][map->width - 1] != '1')
            return 0;
    }
    return (1);
}

void    map_dfs_control(char **visited,int px, int py, t_map *map)
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
    }
    else
        visited[py][px] = '1';
    map_dfs_control(visited, (px + 1), py, map);
    map_dfs_control(visited, px, py + 1, map);
    map_dfs_control(visited, (px - 1), py, map);
    map_dfs_control(visited, px, (py - 1), map);
}

void    map_control(t_map *map)
{
    char    **visited;

    visited = (char **)malloc(sizeof(map->map_pattern));
    if (!visited)
        ft_error("Malloc Error", map);
    if (map->player != 1 || map->exit != 1 || map->collectables <= 0)
        ft_error("\nMap element counts must {player = 1,\n Exit = 1,\n Collectable != 0}", map);
    if(!map_wall_control(map, -1, -1))
         ft_error("The map must be completely surrounded by walls.", map);
    visited = map->map_pattern;
    map_dfs_control(visited, map->player_x, map->player_y, map);
    matris_free(visited);
    if (map->exit != 0 || map->collectables != 0)
        ft_error("Map Dynamic Error", map);
}