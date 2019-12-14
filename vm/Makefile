# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykliek <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 13:02:57 by ykliek            #+#    #+#              #
#    Updated: 2019/10/29 18:40:00 by eamielin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ../libft
LIBFT = ../libft/libft.a
INC_COREWAR = ./includes/virtual_machine.h

SRCS = src/checker.c \
		src/commands_1.c \
		src/create_arena.c \
		src/cycle.c \
		src/dblst_tools.c \
		src/define.c \
		src/dump.c \
		src/error_management.c \
		src/order.c \
		src/reader.c \
		src/virtual_machine.c \
		src/get.c \
		src/get_arg.c \
		src/pars_args.c \
		src/skip.c \
		src/commands_2.c \
		src/commands_3.c \
		src/commands_4.c \
		src/check_code_type.c \
		../resources/op.c

O_FILES		= $(addprefix , $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(O_FILES)
	$(CC) $(O_FILES) $(CFLAGS) -o $(NAME) -lft -L $(LIBFT_DIR)
	@printf '\033[1;32m[ ✔ ] %s\n\033[0m' "Create binary corewar"

$%.o: %.c $(INC_COREWAR)
		gcc -c $< -o $@ $(CFLAGS) -I $(INC_COREWAR)

$(LIBFT):
	make -C $(LIBFT_DIR)
	@printf '\033[1;32m[ ✔ ] %s\n\033[0m' "Compile lib"

clean:
	rm -rf $(O_FILES)
	make clean -C $(LIBFT_DIR)
	@printf '\033[1;32m[ ✔ ] %s\n\033[0m' "All *.o were cleaned"

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)
	@printf '\033[1;32m[ ✔ ] %s\n\033[0m' "Libft.a and binary were cleaned"

cleanlib:
	make -C $(LIBFT_DIR) clean

fcleanlib:
	make -C $(LIBFT_DIR) fclean

relib:
	make -C $(LIBFT_DIR) re

re: fclean all

deb :
	$(CC) -o $(NAME) $(SRCS) -I $(INC_COREWAR) $(LIBFT)

.PHONY: clean fclean re libft all
