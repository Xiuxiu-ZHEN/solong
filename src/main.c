/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:41:06 by mipang            #+#    #+#             */
/*   Updated: 2025/05/23 16:00:19 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void	parameter_check(int argc, char **str)
{
	int	len;
	int	fd;

	if (argc != 2)
	{
		ft_printf("Error: Invalid number of arguments.\n");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(str[1]);
	if (len < 5 || ft_strncmp(str[1] + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error: Non valid .ber file.\n");
		exit(EXIT_FAILURE);
	}
	fd = open(str[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Non valid ber - file does not exist.\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	void	*window;
	t_game	g;

	parameter_check(argc, argv);
	g.map = read_map(argv[1]);
	g.mlx = mlx_init();
	if (!g.mlx)
	{
		write(2, "Error: mlx_init failed. DISPLAY might not be set.\n", 50);
		exit(EXIT_FAILURE);
	}
	window = mlx_new_window(g.mlx, g.map.width * 32,
			g.map.height * 32, "so long");
	g.window = window;
	g.move = 0;
	g.tex.player.img = NULL;
	g.tex.wall.img = NULL;
	g.tex.path.img = NULL;
	g.tex.collectible.img = NULL;
	g.tex.exit.img = NULL;
	ft_printf("how many collects: %d\n", g.map.collects);
	load_map(&g);
	render_map(&g);
	mlx_hook(window, 17, 0, handle_exit, &g);
	mlx_key_hook(window, handle_key_move, &g);
	mlx_loop(g.mlx);
	return (0);
}
