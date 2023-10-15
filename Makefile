NAME = fractol
SRC = main.c parse.c atod.c validate_string.c fractol_utils.c move_window.c keys.c scroll.c press.c resize.c change_iter.c init.c render.c render_fractals.c mandel_julia_power.c colour_shift.c colour_functions.c init_legend.c legend_functions.c
OBJ = $(SRC:%.c=obj/%.o)
OBJ_DIR = obj

# MLX related variables
MLX42_SOURCE_DIR = MLX42/source/
MLX42_BUILD_DIR = MLX42/build/
MLX42_LIB = MLX42/build/libmlx42.a

# libft related variables
LIBFT = libft/libft.a
LIBFT_DIR = libft

# variables for compilation
CC = cc
INCLUDES = -iquote includes -iquote libft/includes -iquote MLX42/source/include/MLX42   
MLX_FLAGS = -Iinclude -ldl -lglfw -pthread -lm
# MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
ifdef DEBUG
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
else
CFLAGS = -Wall -Wextra -Werror -Ofast
endif

all: $(LIBFT_DIR) $(NAME)

$(NAME): $(MLX42_LIB) $(LIBFT) $(OBJ)
	@$(CC) $(INCLUDES) $(CFLAGS) $(MLX_FLAGS) -o $@ $(OBJ) $(LIBFT) $(MLX42_LIB)

$(MLX42_LIB):
	@cmake -S $(MLX42_SOURCE_DIR) -B $(MLX42_BUILD_DIR)
	@cmake --build $(MLX42_BUILD_DIR) -j4

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(LIBFT_DIR):
	@git clone https://github.com/jmolenaa/Codam_libft.git $(LIBFT_DIR)

obj/%.o: src/%.c | $(OBJ_DIR)
	@$(CC) $(INCLUDES) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(MLX42_BUILD_DIR)

debug: fclean
	@cmake -DDEBUG=1 -S $(MLX42_SOURCE_DIR) -B $(MLX42_BUILD_DIR)
	@cmake --build $(MLX42_BUILD_DIR) -j4
	@$(MAKE) DEBUG=1 all

re: fclean all
