/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:52:04 by alermi            #+#    #+#             */
/*   Updated: 2025/03/05 13:53:05 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	map;
    ft_memset(&map, 0, sizeof(t_map)); // Bütün verilerin içerisine sıfır attık.
	if (argc == 2)
		init_map(&map, argv[1]);
	else
		ft_error("Invalid Argument : </maps/map.ber>", NULL);
	return (0);
}
