/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 05:43:20 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/21 05:44:30 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_bounds(char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (y >= map_height(map))
		return (0);
	if (x >= (int)ft_strlen(map[y]))
		return (0);
	return (1);
}

void	flood_fill_blocking_exit(char **map, int x, int y, t_flood *flood)
{
	t_stack	stack;
	int		cur_x;
	int		cur_y;
	char	current;

	stack_init(&stack);
	stack_push(&stack, x, y);
	while (!stack_is_empty(&stack))
	{
		stack_pop(&stack, &cur_x, &cur_y);
		if (!check_bounds(map, cur_x, cur_y))
			continue ;
		current = map[cur_y][cur_x];
		if (current == '1' || current == 'F' || current == 'E')
			continue ;
		if (current == 'C')
			flood->found_c++;
		map[cur_y][cur_x] = 'F';
		stack_push(&stack, cur_x - 1, cur_y);
		stack_push(&stack, cur_x + 1, cur_y);
		stack_push(&stack, cur_x, cur_y - 1);
		stack_push(&stack, cur_x, cur_y + 1);
	}
	stack_free(&stack);
}

void	flood_fill_check_exit(char **map, int x, int y, t_flood *flood)
{
	t_stack	stack;
	int		cur_x;
	int		cur_y;
	char	current;

	stack_init(&stack);
	stack_push(&stack, x, y);
	while (!stack_is_empty(&stack))
	{
		stack_pop(&stack, &cur_x, &cur_y);
		if (!check_bounds(map, cur_x, cur_y))
			continue ;
		current = map[cur_y][cur_x];
		if (current == '1' || current == 'F')
			continue ;
		if (current == 'E')
			flood->found_e = 1;
		map[cur_y][cur_x] = 'F';
		stack_push(&stack, cur_x - 1, cur_y);
		stack_push(&stack, cur_x + 1, cur_y);
		stack_push(&stack, cur_x, cur_y - 1);
		stack_push(&stack, cur_x, cur_y + 1);
	}
	stack_free(&stack);
}

char	**duplicate_map(char **map)
{
	char	**map_copy;
	int		i;
	int		height;

	height = map_height(map);
	map_copy = malloc(sizeof(char *) * (height + 1));
	if (!map_copy)
		return (NULL);
	map_copy[height] = NULL;
	i = 0;
	while (i < height)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			free_all_simple(map_copy);
			return (NULL);
		}
		i++;
	}
	return (map_copy);
}
