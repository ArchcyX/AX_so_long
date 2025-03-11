/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:35:19 by alermi            #+#    #+#             */
/*   Updated: 2025/03/10 17:36:52 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/minilibx-linux/mlx.h"

void	player_up(t_game *game, int	*p_pos, void *window, void **img)
{
	game->map.map_pattern[game->map.player_y][game->map.player_x] = '0';
	mlx_put_image_to_window(game->mlx, window, img[0], p_pos[1], p_pos[0]);
	game->map.player_y -= 1;
	game->map.map_pattern[game->map.player_y][game->map.player_x] = 'P';
	mlx_put_image_to_window(game->mlx, window, img[1], p_pos[1], p_pos[0]);
}

void	player_down(t_game *game, int player_x, int player_y, void *window)
{
	game->map.map_pattern[game->map.player_y][game->map.player_x] = '0';
	mlx_put_image_to_window(game->mlx, game->window, game->empyt_img, player_x, player_y);
	game->map.player_y -= 1;
	game->map.map_pattern[game->map.player_y][game->map.player_x] = 'P';
	mlx_put_image_to_window(game->mlx, game->window, game->player_img, player_x, player_y);
}

void	player_right(t_game *game, int player_x, int player_y, void *window)
{
	game->map.map_pattern[game->map.player_y][game->map.player_x] = '0';
	mlx_put_image_to_window(game->mlx, game->window, game->empyt_img, player_x, player_y);
	game->map.player_y -= 1;
	game->map.map_pattern[game->map.player_y][game->map.player_x] = 'P';
	mlx_put_image_to_window(game->mlx, game->window, game->player_img, player_x, player_y);
}

void	player_left(t_game *game, int player_x, int player_y, void *window)
{
	game->map.map_pattern[game->map.player_y][game->map.player_x] = '0';
	mlx_put_image_to_window(game->mlx, window, game->empyt_img, player_x, player_y);
	game->map.player_y -= 1;
	game->map.map_pattern[game->map.player_y][game->map.player_x] = 'P';
	mlx_put_image_to_window(game->mlx, game->window, game->player_img, player_x, player_y);
}

