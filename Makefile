# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 17:14:53 by mpoplow           #+#    #+#              #
#    Updated: 2024/12/06 16:00:16 by mpoplow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= so_long
LIBMLX	= ./MLX42

CFILES 	= src/test.c src/main_so_long.c src/eee.c
OFILES 	= $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
MLXFLAGS = -ldl -lglfw -pthread -lm

all: clone $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clone:
	@if [ ! -d "MLX42" ]; then \
		echo "\033[1;34mDownloading MLX42...\033[0m"; \
		git clone https://github.com/codam-coding-college/MLX42.git MLX42 > /dev/null 2>&1; \
	else \
		echo "\033[1;31mMLX42 exists!\033[0m"; \
	fi


$(NAME): $(OFILES)
	@echo "\033[1;32mCREATE PROGRAM: SO_LONG\033[0m"
	@make all -C libft
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make all -C $(LIBMLX)/build -j4
	@cp libft/libft.a .
	@rm libft/libft.a
	@cp $(LIBMLX)/build/libmlx42.a .
	@cc $(CFILES) libft.a libmlx42.a $(MLXFLAGS) -I $(LIBMLX)/include -o $(NAME) 

clean:
	@make clean -C libft
	@make clean -C $(LIBMLX)/build
	@rm -f $(OFILES)
	@rm -f libft.a && rm -f libmlx42.a

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@rm -rf ./MLX42
	
re: clean all

.PHONY: all clone clean fclean re
