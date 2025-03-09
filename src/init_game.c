#include "../includes/so_long.h"
#include "../includes/minilibx-linux/mlx.h"
#include "../includes/minilibx-linux/mlx_int.h"
#include <stdio.h>

int key_event(int keycode, t_game *game)
{
	printf("naber müdür: %d\n", keycode);
	if (keycode == 65307)
		ft_error("exit", &game->map);
}

int mouse_event(int button, int x, int y, t_game *game)
{
	printf("Mouse clicked at (%d, %d) with button %d\n", x, y, button);
	printf("%p\n", game->collectable_img);
	mlx_put_image_to_window(game->mlx, game->window, game->collectable_img, x, y);
	return (0);
}

void    fill_map(t_game *game)
{
	int	i;
	int	j;
	int	multiplexer_x;
	int	multiplexer_y;

	i = 0;
	j = 0;
	multiplexer_x = 0;
	multiplexer_y = 0;
	while (game->map.map_pattern[i])
	{
		multiplexer_x = 0;
		j = 0;
		while (game->map.map_pattern[i][j] != '\n')
		{
			if (game->map.map_pattern[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall_img, j + multiplexer_x, i + multiplexer_y );
			else if (game->map.map_pattern[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->window, game->place_img,j + multiplexer_x, i + multiplexer_y );
			else if (game->map.map_pattern[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit_img, j + multiplexer_x, i + multiplexer_y );
			else if (game->map.map_pattern[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->collectable_img,j + multiplexer_x, i + multiplexer_y );
			multiplexer_x += 64;
			j++;
		}
		multiplexer_y += 64;
		i++;
	}
}

void    init_game(t_game *game)
{
	game->mlx = mlx_init();
	//MLX GARİBAN DEĞİL FREELENECEK MAHMUT
	if (!game->mlx)
	ft_error("Gardaş Oyun Yok TÜH", &game->map);
	game->window = mlx_new_window(game->mlx, game->map.width * 64, game->map.height * 64, "POLAT MEMATİ");
	if (!game->window)
	ft_error("Gardaş Bennncere yok", &game->map);
	
	int h;
	int w;
	game->collectable_img = mlx_xpm_file_to_image(game->mlx, "textures/example/collectable.xpm", &w, &h);
	if (game->collectable_img == NULL)
		ft_error("asdasd  ", &game->map);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/example/exit.xpm", &w, &h);
	if (game->exit_img == NULL)
		ft_error("asdasd  ", &game->map);
	game->empyt_img = mlx_xpm_file_to_image(game->mlx, "textures/example/empty.xpm", &w, &h);
	if (game->empyt_img == NULL)
		ft_error("asdasd  ", &game->map);
	game->place_img = mlx_xpm_file_to_image(game->mlx, "textures/example/grass.xpm", &w, &h);
	if (game->place_img == NULL)
		ft_error("asdasd  ", &game->map);
		game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/example/wall.xpm", &w, &h);
	if (game->wall_img == NULL)
		ft_error("asdasd  ", &game->map);
	printf("%p %d %d\n", game->collectable_img, w,h);
	mlx_hook(game->window, 2, KeyPressMask, key_event, game); // 2 = KeyPress, KeyPressMask = 1L << 0
	mlx_hook(game->window, 4, ButtonPressMask, mouse_event, game);   // 4 = ButtonPress
	fill_map(game);
	if(mlx_loop(game->mlx))
		ft_error("aga ", &game->map);
}
