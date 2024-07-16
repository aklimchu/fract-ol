# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 11:18:05 by aklimchu          #+#    #+#              #
#    Updated: 2024/07/16 11:30:16 by aklimchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		= fractol

# Compiler
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -ggdb3 -I $(LIBFT_DIR)
RM			= rm -f

# Minilibx
MLX_PATH	= mlx_linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_DIR	= libft/
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

# Source / OBJ files / Includes
SRC 		= main.c choose_color.c \
			tools.c fractals.c \
			ft_atoi_double.c check_input.c \
			trgb.c
OBJ 		= $(SRC:.c=.o)
INCLUDE		= -I "./"

# Rules
all:		$(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDE) $^ -c -o $@

$(NAME):	$(OBJ)
	@make -C $(LIBFT_DIR)		# make libft
	@make -C $(MLX_PATH)		# make mlx
	@cp $(LIBFT_LIB) $(NAME)	# copy libft to current
	@cp $(MLX) $(NAME)			# copy libft to current
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(MLX) $(INCLUDE) -lXext -lX11 -lm -o $(NAME)

clean:
	$(RM) $(OBJ) 
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_PATH)

fclean:		clean 
	$(RM) $(NAME) $(LIBFT_LIB) $(MLX)

re: 		fclean all

.PHONY: 	all clean fclean re
