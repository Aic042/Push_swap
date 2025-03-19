# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 21:01:27 by root              #+#    #+#              #
#    Updated: 2025/03/15 09:56:47 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap

LIBFT = ./libft
CFLAGS = -Wextra -Wall -Werror -Ofast -g
HEADERS := -I ./include -I $(LIBFT)/include
LIBS = -L$(LIBFT) -lft
SRCS := $(shell find . -iname "*.c")
OBJS := $(SRCS:.c=.o)

all: libft $(NAME)

libft:
		@make -C $(LIBFT) all

%.o: %.c
		cc $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS)
		cc $(OBJS) -o $(NAME) $(LIBS)

clean:
		@rm -rf $(OBJS)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re libft