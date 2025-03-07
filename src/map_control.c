#include "../includes/so_long.h"
#include "../includes/get_next_line/get_next_line.h"
#include <stdio.h>

int map_tile_control(t_map *map)
{
    return (1);
}
void    map_control(t_map *map)
{
    if (map_tile_control(map) == -1 
        || map->player != 1 
        || map->exit != 1 
        || map->collectables <= 0)
        ft_error("\nMap element counts must {player = 1,\n Exit = 1,\n Collectable != 0}", map);
}
