# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 16:29:08 by nivergne          #+#    #+#              #
#    Updated: 2018/12/20 21:15:33 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	./src/check_map.c \
		./src/store_tetris.c \
		./src/fillit_test.c \
		./src/main.c

OBJECTS = $(SRCS:.c=.o)

HEADER = -I ./include

LIB = -lft -L./libft -I./libft

CFLAGS = -Wall -Werror -Wextra

CC = gcc

GRN = \033[0;32m
BLU = \033[1;34m
RED = \x1b[31m
PUR = \x1b[35m
CYAN = \x1b[36m
IGREY = \x1b[40m
UNDER = \x1b[4m
REV = \x1b[7m
BOLD = \x1b[1m
WHITE = \x1b[37m

all: $(NAME)

$(NAME): $(OBJECTS) include/fillit.h
	@echo ""
	@echo "$(CYAN)compilation libft..."
	@$(MAKE) -C libft
	@echo "$(GRN)[SUCCESS]"
	@echo ""
	@#@$(CC) -c $(CFLAGS) $(SRCS)
	@$(CC) $(OBJECTS) -o $(NAME) $(LIB)
	@echo "$(CYAN)create -> $(RED)$(NAME)"
	@echo "$(GRN)[SUCCESS]$(WHITE)"

clean:
	@echo "$(CYAN)$(IGREY)delete object's files"
	@$(MAKE) clean -C libft
	@rm -f $(OBJECTS)
	@echo "$(GRN)[SUCCESS]"
	@echo ""

fclean: clean
	@echo "$(CYAN)$(IGREY)delete -> $(RED)$(NAME)"
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)
	@echo "$(GRN)[SUCCESS]"
	@echo "$(BLU)"

re: fclean all

.PHONY: all clean fclean
.SILENT: $(SRCS)