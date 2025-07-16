/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:35:34 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/23 17:24:04 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_all_collectibles(char **map, t_flood *flood)
{
	char	**map_copy;
	int		x;
	int		y;

	map_copy = duplicate_map(map);
	malloc_error(map_copy);
	find_player_pos(map_copy, &x, &y);
	flood->total_c = count_eles(map, 'C');
	flood_fill_blocking_exit(map_copy, x, y, flood);
	free_all_simple(map_copy);
	if (flood->found_c != flood->total_c)
		return (0);
	return (1);
}

static int	check_exit_reachable(char **map, t_flood *flood)
{
	char	**map_copy;
	int		x;
	int		y;

	map_copy = duplicate_map(map);
	malloc_error(map_copy);
	find_player_pos(map_copy, &x, &y);
	flood_fill_check_exit(map_copy, x, y, flood);
	free_all_simple(map_copy);
	if (!flood->found_e)
		return (0);
	return (1);
}

int	map_check_path_valid(char **map)
{
	t_flood	flood;

	flood.found_c = 0;
	flood.found_e = 0;
	flood.total_c = 0;
	if (!check_all_collectibles(map, &flood))
		return (0);
	if (!check_exit_reachable(map, &flood))
		return (0);
	return (1);
}
