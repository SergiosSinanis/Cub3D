NAME = cub3D

BONUS = cub3D_bonus

INCLUDES = ./includes ./srcs/libft

SRCS_DIR = ./srcs
LIBFT_DIR = ./srcs/libft
PARSING_DIR = ./srcs/parsing
RAYCASTING_DIR = ./srcs/raycasting
CONTROLS_DIR = ./srcs/controls
RENDER_DIR = ./srcs/render
UTILS_DIR = ./srcs/utils

SRC = ${addprefix $(SRCS_DIR)/, main.c}
RAYCASTING_SRC = ${addprefix $(RAYCASTING_DIR)/, ray_init.c raycast_init_utils.c raycast_utils.c horizontal_hit.c vertical_hit.c raycast_hit_pos.c raycast.c}
PARSING_SRC = ${addprefix $(PARSING_DIR)/, convert_file.c flood_fill.c map_parsing.c parsing_utils.c read_map.c parse_tiles_colors.c parsing_check.c init_game.c}
CONTROLS_SRC = ${addprefix $(CONTROLS_DIR)/, player_moves.c}
RENDER_SRC =  ${addprefix $(RENDER_DIR)/, render_utils.c render.c}
UTILS_SRC = ${addprefix ${UTILS_DIR}/, utils.c}

SRCS = $(SRC) $(RAYCASTING_SRC) $(PARSING_SRC) $(RENDER_SRC) $(CONTROLS_SRC) $(UTILS_SRC)

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

MLX_PATH = ./minilibx/

MLX_NAME = libmlx.a

MLX = $(MLX_PATH)$(MLX_NAME)

MLX_FLAGS = -lXext -lX11 -lm

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I ./includes -I $(LIBFT_DIR) -I $(MLX_PATH)

all: $(MLX) $(LIBFT) $(NAME)

bonus: $(MLX) $(LIBFT) $(BONUS)

$(MLX):
	make -C $(MLX_PATH)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(BONUS): $(OBJS)
	cc $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(BONUS)

%.o: %.c
	cc -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_PATH) clean

re: fclean all

bonus_clean: clean

bonus_fclean: fclean

bonus_re: fclean bonus
