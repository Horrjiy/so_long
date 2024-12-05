# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 17:14:53 by mpoplow           #+#    #+#              #
#    Updated: 2024/12/05 17:00:58 by mpoplow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= so_long
LIBMLX	:= ./MLX42

CFILES 	= src/test.c 
OFILES 	= $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	make all -C libft
	cmake $(LIBMLX) -B $(LIBMLX)/build && make all -C $(LIBMLX)/build
	cc $(CFILES) -o $(NAME)
	@cp libft/libft.a .
	@rm libft/libft.a
	@cp $(LIBMLX)/build/libmlx42.a .

clean:
	@make clean -C libft
	@make clean -C $(LIBMLX)/build
	@rm -f $(OFILES)
	@rm -rf $

fclean: clean
	rm -f $(NAME)
	rm -f libft.a && rm -f libmlx42.a
	@make clean -C libft
	@make clean -C $(LIBMLX)/build
	

re: clean all

.PHONY: all clean fclean re
