CC = cc
CFLAGS = -Wall -Wextra -Werror -g

GREEN   = \033[32;1m
RED     = \033[31;49;1m
YELLOW  = \033[33;49;1m
RESET   = \033[0m

# Dizinler
OBJ_DIR = obj
LIBFT_DIR = includes/libft
MLX_DIR = includes/minilibx-linux
GNL_SRCS = includes/get_next_line/get_next_line.c \
           includes/get_next_line/get_next_line_utils.c

# Dosyalar
NAME = so_long
SRCS = 	src/error.c 		\
		src/map_control.c	\
		src/player_motion.c \
       	src/init_game.c 	\
		src/map_creat.c 	\
		src/so_long.c

OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

# Kütüphaneler
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)	
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL_SRCS) $(MLX_FLAGS) -o $(NAME)
	@echo "\n $(GREEN) So_long Created ⚡$(RESET) \n"

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "\n $(YELLOW) Object file created $(RESET) \n"

$(LIBFT):
	@make -C $(LIBFT_DIR) >/dev/null 2>&1
	@make clean -C $(LIBFT_DIR) >/dev/null 2>&1
	@echo "\n $(YELLOW) Libft included $(RESET) \n"

$(MLX):
	@make -C $(MLX_DIR) >/dev/null 2>&1
	@echo "\n $(YELLOW) Mlx Included $(RESET) \n"

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR) >/dev/null 2>&1
	@make clean -C $(MLX_DIR) >/dev/null 2>&1
	@echo "\n $(RED) Object removed ❌\n$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR) >/dev/null 2>&1
	@echo "\n $(RED) Compiled file removed ❌\n\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re
