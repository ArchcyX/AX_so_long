#include "../includes/so_long.h"
#include "../includes/get_next_line/get_next_line.h"

int map_size_control(t_map *map)
{
    int     fd;
    int     i;
    char    *str;
    int     checker;

    i = 0;
    checker = 0;
    fd = open(map->map_name, O_RDONLY);
    if (!fd)
        ft_error(11);
    str = get_next_line(fd);
    if (!str)
    {
        free(str);
        ft_error(13);
    }
    while (str)
    {
        free(str);
        str = get_next_line(fd);   
    }
    return (1);
}
int map_control(t_map *map)
{
    int checker;

    checker = 0;
    checker = map_size_control(map);
}
