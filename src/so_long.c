/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:52:04 by alermi            #+#    #+#             */
/*   Updated: 2025/03/09 15:10:21 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft/libft.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc == 2 && ft_strlen(argv[1]) > 4
		&& ft_strnstr(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4))
	{
		init_map(&game.map, argv[1]);
		init_game(&game);
	}
	else
		ft_map_error("Invalid Argument : </maps/map.ber>", NULL);
	return (0);
}
