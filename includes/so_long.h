#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <stdbool.h>
#include "get_next_line/get_next_line.h"


#define W 119
#define A 97
#define S 115
#define D 100

#define P_COLLECT "textures/xpm/collectable.xpm"
#define P_EXIT "textures/xpm/exit.xpm"
#define P_PLACE "textures/xpm/place.xpm"
#define P_WALL "textures/xpm/wall.xpm"
#define P_PLAYER "textures/xpm/player.xpm"

typedef struct s_map {
    char    **map_pattern;
    int     width;
    int     height;
    int     collectables;
    int     player;
    int     exit;
    int     player_x;
    int     player_y;
}   t_map;

typedef struct s_game {
    void    *mlx;
    void    *window;
    void    *player_img;
    void    *collectable_img;
    void    *exit_img;
    void    *empyt_img;
    void    *place_img;
    void    *wall_img;
    t_map   map;
} t_game;

//#########[INIT-FUNCTIONS] #######//
void    init_map(t_map *map, char *file_path);
void    init_game(t_game *game);
void    calculate_size(t_map *map, int fd);
void    map_creator(t_map *map, char *file_path);
void	init_images(t_game *game);

//#########[ERROR AND FREE FUNCTIONS] #######//
void    ft_map_error(char *error, t_map *map);
void	matris_free(char **str);
void	ft_game_error(char *error, t_game *game);

//#########[MAP-CREAT FUNCTIONS] #######//
void    map_control(t_map *map);
void    map_tile_size(t_map *map);
int     map_tile_control(t_map *map);
int     map_wall_control(t_map *map, int x, int y);
//#########[MAP-CREAT FUNCTIONS] #######//
void    map_dfs_control(char **visited,int px, int py, t_map *map);


//###########[PLAYER MOVEMENT]###########//
void	player_up(t_game *game, int	x, int y);

// void	player_down(t_game *game, int player_x, int player_y);
// void	player_right(t_game *game, int player_x, int player_y);
// void	player_left(t_game *game, int player_x, int player_y);

#endif

/*
||-----------------------

- Error 10 = arg count error
- Error 11 = file descriptor
- Error 12 = Malloc error
- Error 13 = Map size Error
- Error -42 = Using program error

*/