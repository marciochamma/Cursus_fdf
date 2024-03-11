# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 17:25:13 by mchamma           #+#    #+#              #
#    Updated: 2023/10/24 15:05:18 by mchamma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =  libft.a
FLAGS = -Werror -Wextra -Wall

SRC_DIR = src/
OBJ_DIR = obj/

SRC_FILES = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_ishexa.c ft_isprint.c \
	ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c  ft_memset.c \
	ft_intabs.c ft_intcmp.c ft_intsign.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	ft_atoi_hexa.c ft_atoi.c ft_itoa.c ft_tolower.c ft_toupper.c \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
	get_next_line.c \
	ft_printf.c ft_putchar_pf.c ft_putstr_pf.c ft_putptr_pf.c \
	ft_putnbr_pf.c ft_putnbrbase_pf.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))
INC = -I inc/
LIB = $(NAME)

#--------------------//-------------------#

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(LIB) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	cc $(FLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
	make clean

.PHONY: all bonus clean fclean re run