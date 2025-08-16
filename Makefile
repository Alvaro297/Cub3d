NAME := cub3D
BONUS_NAME := cub3D_bonus

CC := cc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR := libft_cub3d/
LIBFT_LIB := $(LIBFT_DIR)libft.a

MINILIB_DIR := minilibx/
MINILIB_LIB := $(MINILIB_DIR)libmlx_$(shell uname).a

INCLUDES := -I. -Iincludes -I$(MINILIB_DIR)

OBJ_DIR := obj

SRCS := \
	cub3d/main.c \
	cub3d/initializer/init_cub3d.c \
	cub3d/initializer/init_cub3d2.c \
	cub3d/read_map/read_map.c \
	cub3d/read_map/handle_map.c \
	cub3d/read_map/utils_read_map.c \
	cub3d/read_map/validate_map.c \
	cub3d/read_map/utils_validate_map.c \
	cub3d/read_map/validade_player.c \
	cub3d/freedoom/freedoom.c \
	cub3d/freedoom/more_freedom.c \
	cub3d/raycast/raycasting.c \
	cub3d/raycast/steps_clean.c \
	cub3d/print_cub3d/print_cub3d.c \
	cub3d/print_cub3d/print_cub3d_help.c \
	cub3d/print_cub3d/load_images.c \
	cub3d/print_cub3d/color_ceiling.c \
	cub3d/print_cub3d/print_textures.c \
	cub3d/player_movement/player_movement.c \
	cub3d/player_movement/movement.c \

OBJ_FILES := $(SRCS:%.c=$(OBJ_DIR)/%.o)
TOTAL := $(words $(SRCS))

BONUS_SRCS := \
	cub3d_bonus/main_bonus.c \
	cub3d_bonus/doors_bonus/doors_bonus.c \
	cub3d_bonus/doors_bonus/doors_utils_bonus.c \
	cub3d_bonus/freedoom_bonus/freedoom_bonus.c \
	cub3d_bonus/freedoom_bonus/more_freedom_bonus.c \
	cub3d_bonus/initializer_bonus/initializer_bonus.c \
	cub3d_bonus/initializer_bonus/init_cub3d_bonus.c \
	cub3d_bonus/minimap_bonus/minimap_bonus.c \
	cub3d_bonus/player_movement_bonus/movement_bonus.c \
	cub3d_bonus/player_movement_bonus/player_movement_bonus.c \
	cub3d_bonus/player_movement_bonus/mouse_utils_bonus.c \
	cub3d_bonus/print_cub3d_bonus/color_ceiling_bonus.c \
	cub3d_bonus/print_cub3d_bonus/print_cub3d_bonus.c \
	cub3d_bonus/print_cub3d_bonus/print_cub3d_help_bonus.c \
	cub3d_bonus/print_cub3d_bonus/load_images_bonus.c \
	cub3d_bonus/print_cub3d_bonus/load_images_utils_bonus.c \
	cub3d_bonus/print_cub3d_bonus/print_textures.c \
	cub3d_bonus/print_cub3d_bonus/print_textures_door.c \
	cub3d_bonus/raycast_bonus/utils_steps_clean_bonus.c \
	cub3d_bonus/raycast_bonus/raycasting_bonus.c \
	cub3d_bonus/raycast_bonus/steps_clean_bonus.c \
	cub3d_bonus/read_map_bonus/handle_map_bonus.c \
	cub3d_bonus/read_map_bonus/read_map_bonus.c \
	cub3d_bonus/read_map_bonus/utils_read_map_bonus.c \
	cub3d_bonus/read_map_bonus/utils_validate_map_bonus.c \
	cub3d_bonus/read_map_bonus/validade_player_bonus.c \
	cub3d_bonus/read_map_bonus/validate_map_bonus.c \
	cub3d_bonus/read_map_bonus/validate_map_bonus_help.c \
	cub3d_bonus/animation/animation.c \

OBJ_FILES := $(SRCS:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ_FILES := $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

TOTAL := $(words $(SRCS))
BONUS_TOTAL := $(words $(BONUS_SRCS))
COUNT := 0

all: $(LIBFT_LIB) $(MINILIB_LIB) $(NAME)

$(LIBFT_LIB):
	@echo "\033[1;33mCompiling libft...\033[0m"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MINILIB_LIB):
	@echo "\033[1;33mCompiling MiniLibX...\033[0m"
	@$(MAKE) -C $(MINILIB_DIR) --no-print-directory

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(LIBFT_LIB) $(MINILIB_LIB) -lm -lX11 -lXext

bonus: $(LIBFT_LIB) $(MINILIB_LIB) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ_FILES)
	@$(CC) $(CFLAGS) $(BONUS_OBJ_FILES) -o $(BONUS_NAME) $(LIBFT_LIB) $(MINILIB_LIB) -lm -lX11 -lXext

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@if echo "$@" | grep -q "_bonus.o"; then \
		index=$$(echo "$(BONUS_OBJ_FILES)" | tr ' ' '\n' | grep -n "$@" | cut -d: -f1); \
		percent=$$(( index * 100 / $(BONUS_TOTAL) )); \
		printf "\033[1;36m[ %3s%% ] Building bonus object %s\033[0m\n" "$$percent" "$@"; \
	else \
		index=$$(echo "$(OBJ_FILES)" | tr ' ' '\n' | grep -n "$@" | cut -d: -f1); \
		percent=$$(( index * 100 / $(TOTAL) )); \
		printf "\033[1;32m[ %3s%% ] Building object %s\033[0m\n" "$$percent" "$@"; \
	fi
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "\033[1;33mCleaning object files...\033[0m"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(MINILIB_DIR) clean --no-print-directory

fclean: clean
	@echo "\033[1;33mRemoving binaries...\033[0m"
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@rm -f $(MINILIB_LIB)

re: fclean all

.PHONY: all clean fclean re bonus