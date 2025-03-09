# Compiler and flags
CC = cc
CFLAGS = -g -Iincludes -I/usr/include/X11

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = includes/libft
MLX_DIR = includes/minilibx-linux
GNL_DIR = includes/get_next_line/get_next_line.c \
		  includes/get_next_line/get_next_line_utils.c

# Files
NAME = so_long
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Linking flags
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL_DIR) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
