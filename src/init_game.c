/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:20:32 by alermi            #+#    #+#             */
/*   Updated: 2025/03/10 17:23:09 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/minilibx-linux/mlx.h"
#include "../includes/minilibx-linux/mlx_int.h"
#include <stdio.h>

int	key_event(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_map_error("exit", &game->map);
	else if (keycode == 119)
		player_up(game, 0, -1);
	else if (keycode == 97)
		player_up(game, -1, 0);
	else if (keycode == 115)	
		player_up(game, 0, 1);	
	else if (keycode == 100)
		player_up(game, 1, 0);

}

int	mouse_event(int button, int x, int y, t_game *game)
{
	printf("Mouse clicked at (%d, %d) with button %d\n", x, y, button);
	return (0);
}

void	fill_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.height - 1)
	{
		x = -1;
		while (game->map.map_pattern[y][++x] != '\n')
		{
			if (game->map.map_pattern[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, 
				game->wall_img, x * 64, y * 64 );
			else if (game->map.map_pattern[y][x] == '0')
				mlx_put_image_to_window(game->mlx, 
				game->window, game->place_img,x * 64, y * 64 );
			else if (game->map.map_pattern[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, 
				game->exit_img, x * 64, y * 64 );
			else if (game->map.map_pattern[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, 
				game->collectable_img,x * 64, y * 64 );
			else if (game->map.map_pattern[y][x] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->window, 
				game->place_img,x * 64, y * 64 );
				mlx_put_image_to_window(game->mlx, game->window,
				game->player_img,x * 64, y * 64 );
			}
		}
	}
}

void    init_game(t_game *game)
{
	int	h;
	int	w;

	game->mlx = mlx_init();
	if (!game->mlx)
		ft_game_error("Gardaş Oyun Yok TÜH", &game->map);
	game->window = mlx_new_window(game->mlx, game->map.width * 64, game->map.height * 64, "POLAT MEMATİ");
	if (!game->window)
		ft_game_error("Gardaş Bennncere yok", &game->map);
	game->collectable_img = mlx_xpm_file_to_image(game->mlx, "textures/example/collectable.xpm", &w, &h);
	if (game->collectable_img == NULL)
		ft_game_error("asdasd  ", &game->map);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/example/exit.xpm", &w, &h);
	if (game->exit_img == NULL)
		ft_game_error("asdasd  ", &game->map);
	game->empyt_img = mlx_xpm_file_to_image(game->mlx, "textures/example/empty.xpm", &w, &h);
	if (game->empyt_img == NULL)
		ft_game_error("asdasd  ", &game->map);
	game->place_img = mlx_xpm_file_to_image(game->mlx, "textures/example/grass.xpm", &w, &h);
	if (game->place_img == NULL)
		ft_game_error("asdasd  ", &game->map);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/example/wall.xpm", &w, &h);
	if (game->wall_img == NULL)
		ft_game_error("asdasd  ", &game->map);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/example/player.xpm", &w, &h);
	if (game->wall_img == NULL)
		ft_game_error("asdasd  ", &game->map);
	mlx_hook(game->window, 2, KeyPressMask, key_event, game); // 2 = KeyPress, KeyPressMask = 1L << 0
	mlx_hook(game->window, 4, ButtonPressMask, mouse_event, game);   // 4 = ButtonPress
	fill_map(game);
	if(mlx_loop(game->mlx))
		ft_game_error("aga ", &game->map);
}
