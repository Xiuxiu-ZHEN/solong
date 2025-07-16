/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:53:52 by mipang            #+#    #+#             */
/*   Updated: 2025/05/23 17:24:35 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/src/ft_printf/ft_printf.h"

void	map_error()
{
	write(2, "Error\nInvalid map format.\n", 27);
	exit(EXIT_FAILURE);
}

void	map_error_with_fd(int fd)
{
	if (fd >= 0)
		close(fd);
	write(2, "Error\nInvalid map format.\n", 27);
	exit(EXIT_FAILURE);
}

void	malloc_error(void *ptr)
{
	if (!ptr)
		map_error();
}

int	handle_exit(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	free_and_exit(g);
	return (0);
}

void	free_all_simple(char **ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_all_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
