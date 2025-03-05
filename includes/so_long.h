#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <stdbool.h>
#include "get_next_line/get_next_line.h"

typedef struct s_map {
    char    **map_pattern;
    int     width;
    int     height;
    int     collectables;
    int    player;
    int    exit;
}   t_map;

typedef struct s_player {
    int pos_x;
    int pos_y;
}   t_player;

//#########[INIT-FUNCTIONS] #######//
void    init_map(t_map *map, char *file_path);
void    calculate_size(t_map *map, int fd);
void    map_creator(t_map *map, char *file_path);

//#########[ERROR AND FREE FUNCTIONS] #######//
void    ft_error(char *error);
void	matris_free(char **str);

//#########[MAP-CREAT FUNCTIONS] #######//
void     map_control(t_map *map);
void     map_tile_size(t_map *map);
int     map_tile_control(t_map *map);
#endif

/*
||-----------------------

- Error 10 = arg count error
- Error 11 = file descriptor
- Error 12 = Malloc error
- Error 13 = Map size Error
- Error -42 = Using program error

*/