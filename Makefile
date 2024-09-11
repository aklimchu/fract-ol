# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 11:18:05 by aklimchu          #+#    #+#              #
#    Updated: 2024/09/11 10:54:30 by aklimchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Program name
NAME		= fractol

# Compiler
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -I $(LIBFT_DIR)
RM			= rm -rf

# Minilibx
MLX_PATH	= mlx_linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_DIR	= libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

# Source / OBJ files / Includes
SRC 		= main.c choose_color.c \
			tools.c mandelbrot.c \
			ft_atoi_double.c check_input.c \
			trgb.c julia.c pythagoras.c \
			zoom_shift.c zoom_pyth.c \
			events.c
OBJ 		= $(SRC:.c=.o)
INCLUDE		= -I "./"

# Rules
all:	libmlx $(NAME)

libmlx: .mlx

.mlx:
	@echo "$(GREEN)Compiling mlx... $(DEF_COLOR)"
	@touch .mlx
	@git clone https://github.com/42Paris/minilibx-linux.git $(MLX_PATH)
	@make -C $(MLX_PATH) --no-print-directory		# make mlx

%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDE) $^ -c -o $@

$(NAME):	$(OBJ)
	@echo "$(GREEN)Compiling libft... $(DEF_COLOR)"
	@make -C $(LIBFT_DIR) --no-print-directory		# make libft
	@cp $(LIBFT_LIB) $(NAME)	# copy libft to current
	@cp $(MLX) $(NAME)			# copy libft to current
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(MLX) $(INCLUDE) -lXext -lX11 -lm -o $(NAME)
	@echo "$(GREEN)SUCCESS, FRACTOL IS READY $(DEF_COLOR)"

clean:
	@echo "$(GREEN)Deleting object files... $(DEF_COLOR)"
	$(RM) $(OBJ) 
	@make clean -C $(LIBFT_DIR) --no-print-directory

fclean:		clean
	@echo "$(GREEN)Deleting fractol... $(DEF_COLOR)"
	$(RM) $(NAME) $(LIBFT_LIB) $(MLX) .mlx $(MLX_PATH)
	@echo "$(GREEN)CLEAR $(DEF_COLOR)"

re: 		fclean all

.PHONY: 	all clean fclean re
