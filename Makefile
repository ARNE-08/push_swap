# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 11:11:25 by psaengha          #+#    #+#              #
#    Updated: 2023/08/23 11:11:25 by psaengha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	push_swap.c \
		check_error.c
OBJ = $(SRC:%.c=%.o)
LIBFT = Libft/libft.a

INCS_DIR = ./includes
IFLAGS = -I $(INCS_DIR)
#LEAK = -fsanitize=address
GCC_FLAGS = gcc -Wall -Wextra -Werror -g -Iinclude
# GCC_FLAGS = gcc -Wall -Wextra -Werror -g -Iinclude $(LEAK)

all: $(NAME)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME) : $(OBJ)
	make -C ./Libft
	$(GCC_FLAGS) $^ $(LIBFT) -o $@
# $(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C ./Libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C ./Libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re