#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct s_map {
    char    **map_pattern;
    int     width;
    int     height;
}   t_map;

typedef struct s_player {
    int pos_x;
    int pos_y;
}   t_player;


void    init_map(t_map *map, char *file_path);
void    calculate_size(t_map *map, int fd);
void    ft_error(int err_no);
char    **map_creator(t_map *map);
//int     map_control(t_map *map);
//int     map_size_control(t_map *map);
#endif

/*
||-----------------------

- Error 10 = arg count error
- Error 11 = file descriptor
- Error 12 = Malloc error
- Error 13 = Map size Error
- Error -42 = Using program error

*/