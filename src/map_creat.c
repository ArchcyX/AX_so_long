#include "../includes/so_long.h"
#include "../includes/libft/libft.h"
#include <stdio.h>

void    init_map(t_map *map, char *file_path)
{
	int     i;
	int		fd;

	i = 0;
	fd = open(file_path, O_RDONLY);	
	if(fd == -1)
		ft_error(11);
	map->height = 0;
	map->width = 0;
	
	calculate_size(map, fd);
	map->map_pattern = map_creator(map);
//	if (map_control(map->map_pattern))
//		ft_error(16);
	close(fd);
}

void    calculate_size(t_map *map, int fd)
{
	char    *str;

	str = get_next_line(fd);	
	if (!str)
	{
		free(str);
		ft_error(15);
	}
	map->width = ft_strlen(str);
	map->height = 1;
	while (str)
	{
		if (ft_strlen(str) != map->width)
		{
			close(fd);
			free(str);
			ft_error(13);
		}
		free(str);
		map->height++;
		str = get_next_line(fd);
	}
}

char **map_creator(t_map *map)
{
	int fd;
	int counter = 0;
	char **str;
	char *line;

	str = (char **)malloc(sizeof(char *) * map->height);
	fd = open("maps/map.ber", O_RDONLY);
	if (fd == -1)
		ft_error(11);
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		ft_error(12);
	}
	while (line)
	{
		str[counter] = line;
		free(line);
		line = get_next_line(fd);
		counter++;
	}
	str[counter] = NULL;

	close(fd);
	return (str);
}