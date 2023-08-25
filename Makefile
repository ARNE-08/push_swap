# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaengha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 11:11:25 by psaengha          #+#    #+#              #
#    Updated: 2023/08/25 13:02:16 by psaengha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	main.c \
		check_error.c \
		check_duplicate.c \
		check_nonlimit.c \
		stack.c
OBJ = $(SRC:%.c=%.o)
LIBFT = utils/libft/libft.a
PRINTF = utils/ft_printf/libftprintf.a

INCS_DIR = ./includes
IFLAGS = -I $(INCS_DIR)
#LEAK = -fsanitize=address
GCC_FLAGS = gcc -Wall -Wextra -Werror -g -Iinclude
# GCC_FLAGS = gcc -Wall -Wextra -Werror -g -Iinclude $(LEAK)

all: $(NAME)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME) : $(OBJ)
	make -C ./utils/libft
	make -C ./utils/ft_printf
	$(GCC_FLAGS) $^ $(LIBFT) $(PRINTF) -o $@
# $(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C ./utils/libft
	make clean -C ./utils/ft_printf
	rm -rf $(OBJ)

fclean : clean
	make fclean -C ./utils/libft
	make fclean -C ./utils/ft_printf
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
