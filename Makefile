NAME = fractol

CC = cc

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror -Iinclude -I./MLX42/include -I$(LIBFT_DIR) -g
LDFLAGS = -L.//MLX42/build -lmlx42 -lglfw -lm -ldl -pthread

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) ./MLX42/build/libmlx42.a
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

MLX42/build/libmlx42.a:
	cmake -S MLX42 -B ./MLX42/build -DMLX42_BUILD_EXAMPLES=OFF
	cmake --build ./MLX42/build --parallel

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

all: $(NAME)