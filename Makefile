# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 16:29:08 by nivergne          #+#    #+#              #
#    Updated: 2018/12/25 17:54:02 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	./src/parse.c \
		./src/store.c \
		./src/solve.c \
		./src/main.c

OBJECTS = $(SRCS:.c=.o)

HEADER = -I ./include

LIB = -lft -L./libft -I./libft

CFLAGS = -Wall -Werror -Wextra

CC = gcc

$(PRINT):
	@echo "$(BLU)$(BOLD)[compilation fillit ...]"

GRN = \033[0;32m
BLU = \033[1;34m
RED = \x1b[31m
PUR = \x1b[35m
CYAN = \x1b[36m
IGREY = \x1b[40m
UNDER = \x1b[4m
REV = \x1b[7m
BOLD = \x1b[1m
END = \x1b[0m

WHITE = \x1b[37m

all: $(NAME)

$(NAME): $(PRINT) $(OBJECTS) include/fillit.h
	@echo ""
	@echo "$(BLU)$(BOLD)[COMPILE -> $(RED)libft...$(BLU)]$(CYAN)"
	@$(MAKE) -C libft
	@echo "$(GRN)$(BOLD)[libft created]"
	@echo ""
	@$(CC) $(OBJECTS) -o $(NAME) $(LIB)
	@echo "$(BLU)[CREATE -> $(RED)$(NAME)$(BLU)]"
	@echo "$(GRN)$(BOLD)[fillit created]$(WHITE)"

clean:
	@echo "$(CYAN)$(IGREY)$(RED)[$(BOLD)$(BLU)DELETE ->$(CYAN) object's files ...$(END)$(RED)]"
	@$(MAKE) clean -C libft
	@rm -f $(OBJECTS)
	@echo "$(GRN)$(BOLD)[objects deleted]"
	@echo ""

fclean: 
	@echo "$(CYAN)$(IGREY)$(RED)[$(BOLD)$(BLU)DELETE -> $(CYAN)$(NAME) ...$(END)$(RED)]"
	@rm -f $(NAME)
	@echo "$(CYAN)$(IGREY)$(RED)[$(BOLD)$(BLU)DELETE ->$(CYAN) object's files ...$(END)$(RED)]"
	@rm -f $(OBJECTS)
	@$(MAKE) fclean -C libft
	@echo "$(GRN)$(BOLD)[objects and executable deleted]"
	@echo "$(BLU)"

re: fclean all

.PHONY: all clean fclean
.SILENT: $(SRCS)