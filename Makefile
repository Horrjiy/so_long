# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 17:14:53 by mpoplow           #+#    #+#              #
#    Updated: 2024/12/04 20:33:30 by mpoplow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= so_long

CFILES 	=
OFILES 	= $(CFILES:.c=.o)

LIBMLX	:= ./MLX42

$(NAME): $(OFILES)
	cd libft && make all
	cd ../
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4	
	ar rcs $(NAME) $(OFILES)
	cp libft/libft.a .
	cp 
	mv libft.a libmlx.a $(NAME)

clean:
	rm -rf $(OFILES)
	rm -rf $

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re