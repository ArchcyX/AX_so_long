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

int	close_game(t_game *game)
{
	ft_game_close("Closed Game", game);
	return (0);
}

int	key_event(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_game_close("exit", game);
	else if (keycode == W)
		player_motion(game, 0, -1);
	else if (keycode == A)
		player_motion(game, -1, 0);
	else if (keycode == S)
		player_motion(game, 0, 1);
	else if (keycode == D)
		player_motion(game, 1, 0);
	return (0);
}

void	fill_map(t_game *game, int x, int y)
{
	while (++y < game->map.height - 1)
	{
		x = -1;
		while (game->map.map_pattern[y][++x] != '\n')
		{
			if (game->map.map_pattern[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window,
					game->wall_img, x * 64, y * 64);
			else if (game->map.map_pattern[y][x] == '0')
				mlx_put_image_to_window(game->mlx,
					game->window, game->place_img, x * 64, y * 64);
			else if (game->map.map_pattern[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window,
					game->exit_img, x * 64, y * 64);
			else if (game->map.map_pattern[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->collectable_img, x * 64, y * 64);
			else if (game->map.map_pattern[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window,
					game->player_img, x * 64, y * 64);
		}
	}
}

void	init_images(t_game *game)
{
	int	h;
	int	w;

	game->collectable_img = mlx_xpm_file_to_image(game->mlx, P_COLLECT, &w, &h);
	if (game->collectable_img == NULL)
		ft_game_close("Error\nCollectable image not found", game);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, P_EXIT, &w, &h);
	if (game->exit_img == NULL)
		ft_game_close("Error\nExit image not found", game);
	game->place_img = mlx_xpm_file_to_image(game->mlx, P_PLACE, &w, &h);
	if (game->place_img == NULL)
		ft_game_close("Error\nPlace image not found", game);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, P_WALL, &w, &h);
	if (game->wall_img == NULL)
		ft_game_close("Error\nWall image not found", game);
	game->player_img = mlx_xpm_file_to_image(game->mlx, P_PLAYER, &w, &h);
	if (game->player_img == NULL)
		ft_game_close("Error\nPlayer image not found", game);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_game_close("Error\n Game can not startet", game);
	if ((game->map.height * 64) > 2160 || (game->map.width * 64) > 3840)
		ft_game_close("Game Map size so_long", game);
	game->window = mlx_new_window(game->mlx, game->map.width * 64,
			(game->map.height - 1) * 64, "POLAT MEMATİ");
	if (!game->window)
		ft_game_close("Error\n Window can not be opened", game);
	init_images(game);
	game->counter = 0;
	mlx_hook(game->window, 17, 0, close_game, game);
	mlx_hook(game->window, 2, KeyPressMask, key_event, game);
	fill_map(game, -1, -1);
	if (mlx_loop(game->mlx))
		ft_game_close("Error\n Game not opened in loop", game);
}
