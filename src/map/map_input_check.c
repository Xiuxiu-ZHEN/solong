/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:11:56 by mipang            #+#    #+#             */
/*   Updated: 2025/05/21 05:41:18 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_rectangle_check(char **map)
{
	int	i;
	int	width;

	i = 0;
	width = map_width(map);
	while (map[i] != NULL)
	{
		if ((int)ft_strlen(map[i]) != width)
			return (0);
		i ++;
	}
	return (1);
}

static int	map_wall_check_horizon(char **map)
{
	int	i;
	int	height;
	int	width;

	i = 0;
	height = map_height(map);
	width = map_width(map);
	if (height < 1 || width < 1)
		return (0);
	while (map[0][i] != '\0' && map[height - 1][i] != '\0')
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i ++;
	}
	if (i != width)
		return (0);
	return (1);
}

static int	map_wall_check_vertical(char **map)
{
	int	i;
	int	height;
	int	width;

	i = 0;
	height = map_height(map);
	width = map_width(map);
	if (height < 1 || width < 1)
		return (0);
	while (i < height && width > 0)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i ++;
	}
	if (i != height)
		return (0);
	return (1);
}

int	map_input_check(char **map)
{
	if (!map_rectangle_check(map))
	{
		free_all_simple(map);
		map_error_msg("Map is not rectangular.");
	}
	if (!map_element_check(map))
	{
		free_all_simple(map);
		map_error_msg("Invalid map elements: need 1 P, 1 E, ≥1 C.");
	}
	if (!map_wall_check_horizon(map) || !map_wall_check_vertical(map))
	{
		free_all_simple(map);
		map_error_msg("Map is not enclosed by walls.");
	}
	if (!map_check_path_valid(map))
	{
		free_all_simple(map);
		map_error_msg("No valid path to all collectibles and exit.");
	}
	return (1);
}
