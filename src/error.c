/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:50:11 by alermi            #+#    #+#             */
/*   Updated: 2025/03/05 13:50:31 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/minilibx-linux/mlx.h"
#include <stdio.h>

void	free_imp(char *str)
{
	if (str)
		free(str);
	str = NULL;
}

void	matris_free(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free_imp(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_map_error(char *error, t_map *map)
{
	printf("%s", error);
	if (map != NULL)
		matris_free(map->map_pattern);
	exit(1);
}

void	ft_game_error(char *error, t_game *game)
{
	printf("%s", error);
	if (game)
	{
		if (game->collectable_img)
			mlx_destroy_image(game->mlx, game->collectable_img);
		if (game->player_img)
			mlx_destroy_image(game->mlx, game->player_img);
		if (game->place_img)
			mlx_destroy_image(game->mlx, game->place_img);
		if (game->exit_img)
			mlx_destroy_image(game->mlx, game->exit_img);
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		if (game->map.map_pattern)
			matris_free(game->map.map_pattern);
		free(game);
	}
	exit(1);
}

