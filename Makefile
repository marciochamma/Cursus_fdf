# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 12:41:12 by mchamma           #+#    #+#              #
#    Updated: 2023/10/24 15:03:54 by mchamma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Werror -Wextra -Wall

SRC_DIR = src/
OBJ_DIR = obj/

SRC_FILES = fdf.c map_load.c map_draw.c map_dim.c map_utils.c mlx_utils.c \
	prints.c terminate.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

INC = -I inc -I lib/libft/inc/ -I lib/minilibx-linux/
LIB = -L lib/libft/ -lft -L lib/minilibx-linux/ -lmlx_Linux -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) $(INC) $(LIB) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	cc $(FLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	clear

fclean: clean
	rm -f $(NAME)
	clear

re: fclean all
	make clean

.PHONY: all clean fclean re