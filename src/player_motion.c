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
#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		c = (nb + 48);
	write(1, &c, 1);
}

void	player_up(t_game *game, int x, int y)
{
	if ((game->map.map_pattern[game->map.player_y + y]
			[game->map.player_x + x] == '1')
		|| (game->map.map_pattern[game->map.player_y + y]
			[game->map.player_x + x] == 'E' && game->map.collectables != 0))
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
		ft_game_close("SUCCES", game);
	mlx_put_image_to_window(game->mlx, game->window, game->place_img,
		game->map.player_x * 64, game->map.player_y * 64);
	game->map.player_y += y;
	game->map.player_x += x;
	mlx_put_image_to_window(game->mlx, game->window, game->player_img,
		game->map.player_x * 64, game->map.player_y * 64);
	game->counter++;
	write(1, "Step Count :", 13);
	ft_putnbr(game->counter);
	write(1, "\n", 1);
}
