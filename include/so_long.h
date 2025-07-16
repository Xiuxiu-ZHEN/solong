/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <xzhen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:45:50 by xzhen             #+#    #+#             */
/*   Updated: 2025/05/23 17:25:35 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		py_x;
	int		py_y;
	int		collects;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		height;
	int		width;
}	t_img;

typedef struct s_tex
{
	t_img	player;
	t_img	wall;
	t_img	path;
	t_img	collectible;
	t_img	exit;
}	t_tex;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_tex	tex;
	t_map	map;
	int		move;
}	t_game;

typedef struct s_stack_node
{
	int					x;
	int					y;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;
}	t_stack;

typedef struct s_flood
{
	int	found_c;
	int	total_c;
	int	found_e;
}	t_flood;

void	load_map(t_game *g);
void	render_map(t_game *g);
void	map_error(void);
void	map_error_with_fd(int fd);
void	map_error_msg(const char *msg);
void	free_and_exit(t_game *g);
void	free_all_simple(char **ptr);
void	free_all_map(char **map);
void	malloc_error(void *ptr);
void	find_player_pos(char **map, int *x, int *y);

char	**lst_to_map(const char *map_filename);

int		handle_exit(void *param);
int		handle_key_move(int keycode, t_game *g);
int		map_check_path_valid(char **map);
int		map_input_check(char **map);
int		map_height(char **map);
int		map_width(char **map);
int		count_eles(char **map, char c);
int		map_element_check(char **map);

t_map	read_map(const char *map_filename);

int		check_bounds(char **map, int x, int y);
void	flood_fill_blocking_exit(char **map, int x, int y, t_flood *flood);
void	flood_fill_check_exit(char **map, int x, int y, t_flood *flood);
char	**duplicate_map(char **map);
void	stack_init(t_stack *stack);
int		stack_is_empty(t_stack *stack);
void	stack_push(t_stack *stack, int x, int y);
int		stack_pop(t_stack *stack, int *x, int *y);
void	stack_free(t_stack *stack);

#endif