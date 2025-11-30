# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 17:12:22 by asoria            #+#    #+#              #
#    Updated: 2025/11/30 09:01:42 by asoria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philo
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror -g -pthread -Iincludes -O2 -march=native

SRC_DIR		:= src
SRC_FILES	:= debug.c \
		   init.c \
		   philo.c \
		   parse_args.c \
		   routine.c \
		   time.c \
		   utils.c

OBJ_DIR		:= obj
OBJ_FILES       :=$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))


all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean:
	rm -f $(NAME)

re: clean fclean all


$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo -e "\033[32m[✔] Built $(NAME)\033[0m"

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
