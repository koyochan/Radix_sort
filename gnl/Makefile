# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 14:00:00 by kotkobay          #+#    #+#              #
#    Updated: 2024/10/09 19:16:47 by kotkobay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror

GNL_SRC = get_next_line.c get_next_line_utils.c
GNL_OBJ = $(GNL_SRC:.c=.o)
GNL_LIB = libgnl.a

all: $(GNL_LIB)

$(GNL_LIB): $(GNL_OBJ)
	ar rcs $(GNL_LIB) $(GNL_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(GNL_OBJ)

fclean: clean
	rm -f $(GNL_LIB)

re: fclean all

.PHONY: all clean fclean re