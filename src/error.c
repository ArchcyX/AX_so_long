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
	if (!game && !&game->map)
	{
		matris_free(game->map.map_pattern);
		free(game->mlx);
		free(game->window);
	}
	exit(1);
}
