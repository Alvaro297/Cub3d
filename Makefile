NAME := cub3D

CC := cc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR := libft_cub3d/
LIBFT_LIB := $(LIBFT_DIR)libft.a

MINILIB_DIR := minilibx-linux/
MINILIB_LIB := $(MINILIB_DIR)libmlx_$(shell uname).a

INCLUDES := -I. -Iincludes -I$(MINILIB_DIR)

OBJ_DIR := obj

SRCS := \
	main.c \
	initializer/init_cub3d.c \
	initializer/init_cub3d2.c \
	read_map/read_map.c \
	read_map/handle_map.c \
	read_map/utils_read_map.c \
	read_map/validate_map.c \
	read_map/utils_validate_map.c \
	read_map/validade_player.c \
	freedoom/freedoom.c \
	raycast/raycasting.c \
	raycast/steps_clean.c \
	print_cub3d/print_cub3d.c \
	print_cub3d/load_images.c \
	print_cub3d/color_ceiling.c \
	print_cub3d/print_textures.c \
	player_movement/player_movement.c \
	player_movement/movement.c \
	animation/animation.c \

OBJ_FILES := $(SRCS:%.c=$(OBJ_DIR)/%.o)

TOTAL := $(words $(SRCS))

all: $(LIBFT_LIB) $(MINILIB_LIB) $(NAME)

$(LIBFT_LIB):
	@echo "\033[1;33mCompiling libft...\033[0m"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MINILIB_LIB):
	@echo "\033[1;33mCompiling MiniLibX...\033[0m"
	@$(MAKE) -C $(MINILIB_DIR) --no-print-directory

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(LIBFT_LIB) $(MINILIB_LIB) -lm -lX11 -lXext

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@bash -c ' \
		echo "\033[1;32m[ $$(($(shell ls $(OBJ_DIR) 2>/dev/null | wc -l) * 100 / $(TOTAL)))% ] Building $@\033[0m"; \
	'
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "\033[1;33mCleaning object files...\033[0m"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(MINILIB_DIR) clean --no-print-directory

fclean: clean
	@echo "\033[1;33mRemoving binary...\033[0m"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@rm -f $(MINILIB_LIB)

re: fclean all

.PHONY: all clean fclean re
