/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:35:25 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/23 17:26:07 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include "../libft/src/ft_printf/ft_printf.h"

t_map	read_map(const char *map_filename)
{
	char	**map_contenu;
	int		fd;
	int		x;
	int		y;
	t_map	map_to_play;

	x = 0;
	y = 0;
	fd = open(map_filename, O_RDONLY);
	if (fd < 0)
		map_error_with_fd(fd);
	map_contenu = lst_to_map(map_filename);
	if (!map_contenu)
	{
		close(fd);
		map_error();
	}
	malloc_error(map_contenu);
	map_input_check(map_contenu);
	find_player_pos(map_contenu, &x, &y);
	map_to_play.map = map_contenu;
	map_to_play.height = map_height(map_contenu);
	map_to_play.width = map_width(map_contenu);
	map_to_play.py_x = x;
	map_to_play.py_y = y;
	map_to_play.collects = count_eles(map_contenu, 'C');
	close(fd);
	return (map_to_play);
}

void	load_image(t_game *g, char *path, t_img *img, char *img_name)
{
	if (access(path, F_OK) == -1)
	{
		ft_printf("Error: %s file does not exist at %s.\n", img_name, path);
		free_and_exit(g);
	}
	img->img = mlx_xpm_file_to_image(g->mlx, path, &img->width, &img->height);
	if (!img->img)
	{
		ft_printf("Error: Failed to load %s XPM file at %s.\n", img_name, path);
		free_and_exit(g);
	}
}

void	load_map(t_game *g)
{
	load_image(g, "./src/xpm/player.xpm", &g->tex.player, "player");
	load_image(g, "./src/xpm/wall.xpm", &g->tex.wall, "wall");
	load_image(g, "./src/xpm/path.xpm", &g->tex.path, "path");
	load_image(g, "./src/xpm/collectible.xpm",
		&g->tex.collectible, "collectible");
	load_image(g, "./src/xpm/exit.xpm", &g->tex.exit, "exit");
}

static	void	draw_map(t_game *g, char c, int x, int y)
{
	t_img	*pic;

	pic = NULL;
	if (c == '0')
		pic = &g->tex.path;
	else if (c == '1')
		pic = &g->tex.wall;
	else if (c == 'C')
		pic = &g->tex.collectible;
	else if (c == 'E')
		pic = &g->tex.exit;
	else if (c == 'P')
		pic = &g->tex.player;
	if (pic)
	{
		mlx_put_image_to_window(g->mlx, g->window, pic->img,
			x * pic->width, y * pic->height);
	}
}

void	render_map(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			draw_map(g, g->map.map[y][x], x, y);
			x++;
		}
		y++;
	}
}
