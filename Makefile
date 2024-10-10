# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 20:29:00 by kotkobay          #+#    #+#              #
#    Updated: 2024/10/10 16:22:52 by kotkobay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
GNL_DIR = gnl
GNL = $(GNL_DIR)/get_next_line.a
NAME = push_swap
SRC = src/main.c src/move.c src/sort.c src/utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(GNL) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFT_DIR) -lft -L./$(GNL_DIR) -lgnl

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(GNL):
	@make -s -C $(GNL_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(GNL_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re