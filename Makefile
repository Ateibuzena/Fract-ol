# Nombre del ejecutable
NAME = fractol

# Compilador
CC = cc

# Directorios
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a

# Includes
INCLUDES = -Iinclude -I$(MLX_DIR)/include -I$(LIBFT_DIR)

# Flags generales
WFLAGS = -Wall -Wextra -Werror
OPTFLAGS = -O3 -Ofast -flto
CFLAGS = $(WFLAGS) $(OPTFLAGS) $(INCLUDES)
LDFLAGS = -L$(MLX_DIR)/build -lmlx42 -lglfw -lm -ldl -pthread $(OPTFLAGS)

# Archivos fuente y objetos
SRCS = $(shell find $(SRC_DIR) -name "*.c")
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Regla principal
all: $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(LIBFT)

# Regla para compilar objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilar libft si no existe
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compilar MLX42 si no existe
$(MLX_LIB):
	cmake -S $(MLX_DIR) -B $(MLX_DIR)/build -DMLX42_BUILD_EXAMPLES=OFF
	cmake --build $(MLX_DIR)/build --parallel

# Limpieza de objetos
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

# Limpieza completa
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Recompliación completa
re: fclean all

.PHONY: all clean fclean re