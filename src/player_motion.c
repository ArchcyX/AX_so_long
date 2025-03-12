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
#include <stdio.h>

void	player_up(t_game *game, int	x, int y)
{
	printf("%d\n",game->map.collectables);
	if (game->map.map_pattern[game->map.player_y + y]
		[game->map.player_x + x] == '1')
		return ;
	else if (game->map.map_pattern[game->map.player_y + y]
		[game->map.player_x + x] == 'E' && game->map.collectables != 0)
		return ;
	else if (game->map.map_pattern[game->map.player_y + y]
		[game->map.player_x + x] == 'C')
	{
		game->map.collectables--;
		game->map.map_pattern[game->map.player_y + y]
		[game->map.player_x + x] = '0';
	}
	else if (game->map.map_pattern[game->map.player_y + y]
		[game->map.player_x + x] == 'E' && game->map.collectables == 0)
		ft_game_error("SUCCES", game);
	mlx_put_image_to_window(game->mlx, game->window, game->place_img, 
		game->map.player_x * 64, game->map.player_y * 64);
	game->map.player_y += y;
	game->map.player_x += x;
	mlx_put_image_to_window(game->mlx, game->window, game->player_img, 
		game->map.player_x * 64, game->map.player_y * 64);

}


