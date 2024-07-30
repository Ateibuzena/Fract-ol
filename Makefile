# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = /home/azubieta/sgoinfre/azubieta/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX42_DIR = /home/azubieta/sgoinfre/azubieta/MLX42
MLX42 = $(MLX42_DIR)/libmlx42.a

INCLUDES = -I$(LIBFT_DIR) -I$(MLX42_DIR)

SRC_DIR = ./src
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c\
		$(SRC_DIR)/keyboard_mouse_window.c $(SRC_DIR)/control.c\
		$(SRC_DIR)/color.c $(SRC_DIR)/mandelbrot.c\
		$(SRC_DIR)/julia.c\

OBJ_DIR = ./objs
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = fractol

# Reglas
all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42) -ldl -lglfw -pthread -lm -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

$(MLX42):
	$(MAKE) -C $(MLX42_DIR)
	$(MAKE) -C $(MLX42_DIR) clean

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX42_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
