/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 05:47:12 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/21 08:26:18 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>
#include "../libft/src/ft_printf/ft_printf.h"

void	free_and_exit(t_game *g)
{
	if (g->tex.player.img)
		mlx_destroy_image(g->mlx, g->tex.player.img);
	if (g->tex.wall.img)
		mlx_destroy_image(g->mlx, g->tex.wall.img);
	if (g->tex.path.img)
		mlx_destroy_image(g->mlx, g->tex.path.img);
	if (g->tex.collectible.img)
		mlx_destroy_image(g->mlx, g->tex.collectible.img);
	if (g->tex.exit.img)
		mlx_destroy_image(g->mlx, g->tex.exit.img);
	if (g->window)
		mlx_destroy_window(g->mlx, g->window);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	if (g->map.map)
		free_all_map(g->map.map);
	exit (EXIT_FAILURE);
}
