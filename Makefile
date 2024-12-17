# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 17:14:53 by mpoplow           #+#    #+#              #
#    Updated: 2024/12/17 17:12:53 by mpoplow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= so_long
LIBMLX	= ./MLX42

CFILES 	= src/loadimg.c src/main.c src/error.c \
			src/mapcheck.c src/mapanalyze.c
OFILES 	= $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
MLXFLAGS = -ldl -lglfw -pthread -lm

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBMLX)/.git:
	@echo "\033[1;34mDownloading MLX42...\033[0m"
	@git clone https://github.com/codam-coding-college/MLX42.git MLX42 > /dev/null 2>&1 

$(NAME): $(LIBMLX)/.git $(OFILES)
	@make all -C libft
	@cmake $(LIBMLX) -B $(LIBMLX)/build > /dev/null 2>&1
	@make all -C $(LIBMLX)/build -j4 > /dev/null 2>&1
	@cc $(CFILES) libft/libft.a \
		$(LIBMLX)/build/libmlx42.a $(MLXFLAGS) -I $(LIBMLX)/include -o $(NAME) 
	@echo "\033[1;32mCREATE PROGRAM: SO_LONG\033[0m"

clean:
	@echo "\033[1;33mCLEAN SO_LONG\033[0m"
	@make fclean -C libft
	@rm -rf MLX42/build
	@rm -f $(OFILES)

fclean: clean
	@echo "\033[1;33mREMOVE PROGRAM SO_LONG\033[0m"
	@rm -f $(NAME)
	@rm -rf ./MLX42
	@echo "\033[1;33mMLX42: delete complete folder\033[0m"

re: clean all

prep: fclean all
	@make clean

.PHONY: all clean fclean re prep
