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
		ft_game_error("exit", game);
	else if (keycode == W)
		player_up(game, 0, -1);
	else if (keycode == A)
		player_up(game, -1, 0);
	else if (keycode == S)
		player_up(game, 0, 1);
	else if (keycode == D)
		player_up(game, 1, 0);
	return (0);
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
			{
				mlx_put_image_to_window(game->mlx, game->window,
					game->place_img, x * 64, y * 64);
				mlx_put_image_to_window(game->mlx, game->window,
					game->player_img, x * 64, y * 64);
			}
		}
	}
}

void	init_images(t_game *game)
{
	int	h;
	int	w;

	game->collectable_img = mlx_xpm_file_to_image(game->mlx, P_COLLECT, &w, &h);
	if (game->collectable_img == NULL)
		ft_game_error("Collectable image not found", game);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, P_EXIT, &w, &h);
	if (game->exit_img == NULL)
		ft_game_error("Exit image not found", game);
	game->place_img = mlx_xpm_file_to_image(game->mlx, P_PLACE, &w, &h);
	if (game->place_img == NULL)
		ft_game_error("Place image not found", game);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, P_WALL, &w, &h);
	if (game->wall_img == NULL)
		ft_game_error("Wall image not found", game);
	game->player_img = mlx_xpm_file_to_image(game->mlx, P_PLAYER, &w, &h);
	if (game->player_img == NULL)
		ft_game_error("Player image not found", game);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_game_error("Error: Game can not startet", game);
	game->window = mlx_new_window(game->mlx, game->map.width * 64,
			game->map.height * 64, "POLAT MEMATİ");
	if (!game->window)
		ft_game_error("Error: Window can not be opened", game);
	init_images(game);
	mlx_hook(game->window, 2, KeyPressMask, key_event, game);
	mlx_hook(game->window, 4, ButtonPressMask, mouse_event, game);
	fill_map(game);
	if (mlx_loop(game->mlx))
		ft_game_error("aga ", game);
}
