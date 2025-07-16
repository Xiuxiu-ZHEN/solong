NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -Iinclude -Iminilibx -I$(LIBFT_DIR)/include

SRCS = src/main.c \
       src/utiles/utiles.c \
       src/map/map_check_path_valid.c \
       src/map/map_elements_check_utiles.c \
       src/map/map_input_check.c \
       src/map/map_get_map.c \
       src/map/load_map.c \
       src/map/map_utils.c \
       src/control/handle_key_move.c \
       src/map/free_stack.c \
       src/map/map_flood_utils.c \
       src/utiles/free_and_exit.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -lXext -lX11 -lm -lbsd

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

mlx: $(MLX)

$(MLX):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
