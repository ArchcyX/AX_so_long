#include "../includes/so_long.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_map map;
    if (argc == 2)
    {
        init_map(&map, argv[1]);
    }
    else
        ft_error(-42);
    return (0);
}