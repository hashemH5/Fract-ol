NAME        = fractol

CC			= cc
CFLAGS 		= -Wall -Werror -Wextra

LIBFT_DIR 	= include/libft
MLX_DIR		= include/minilibx-linux
SRCS_DIR 	= srcs
OBJS_DIR 	= objs
INCLUDE_DIR	= include

LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= $(MLX_DIR)/libmlx.a

SRCS_FILES = $(wildcard $(SRCS_DIR)/*.c)
OBJS_FILES = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS_FILES))

all: $(NAME)

$(NAME): $(OBJS_FILES) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -rf $(OBJS_DIR) 

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
