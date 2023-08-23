# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 23:59:58 by psaengha          #+#    #+#              #
#    Updated: 2023/06/17 23:59:58 by psaengha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

SRCS = push_swap.c \
		ft_atoi.c \
		ft_split.c \
		instruction.c \
		radix_sort.c \
		stack.c

OBJS = $(SRCS:.c=.o)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all : run clean

#compile :
#	$(CC) $(FLAGS) $(SRC) -o push_swap

run :
	./push_swap $(ARG)

clean :
	rm -rf push_swap

re : run clean
