NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I.

AR = ar rcs
RM = rm -f

# 📂 Source and object directories
SRCDIR = src
OBJDIR = obj

# 🔍 Find source files in subdirectories
SRCS := $(shell find $(SRCDIR) -type f -name "*.c")
OBJS := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

HEADERS = libft.h

# 🎨 Colors
RED      = \033[0;31m
GREEN    = \033[0;32m
YELLOW   = \033[0;33m
MAGENTA  = \033[0;35m
PINK = \033[38;2;255;105;180m
CYAN     = \033[0;36m
WHITE    = \033[0;37m
RESET    = \033[0m

# 🚀 Main compilation
all: $(NAME)

# 🔨 Create the .a archive (libft.a)
$(NAME): $(OBJDIR) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(YELLOW)✅ $(NAME) successfully created.$(RESET)"

# 📂 Create object directory
$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)✅ Object directories created.$(RESET)"

# 🏗 Compile .c files to .o, respecting subdirectories
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	@mkdir -p $(dir $@)
	@echo "$(CYAN)🔹 Compiling$(MAGENTA) $<$(CYAN) ->$(PINK) $@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@


# 🧹 Clean object files
clean:
	@echo "$(GREEN)🗑️  Removing object directories...$(RESET)"
	@$(RM) -rf $(OBJDIR)
	@echo "$(YELLOW)✅ Object directories removed.$(RESET)"

# 🧹 Full clean (remove objects and archive)
fclean: clean
	@if [ -f "$(NAME)" ]; then \
		echo "$(GREEN)🚮 Removing $(NAME)...$(RESET)"; \
		$(RM) $(NAME); \
		echo "$(YELLOW)✅ $(NAME) removed.$(RESET)"; \
	fi

# 🔄 Rebuild everything
re: fclean all

.PHONY: all clean fclean re
