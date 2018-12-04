# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 13:46:37 by nivergne          #+#    #+#              #
#    Updated: 2018/12/01 17:51:25 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit

SRCS =	fillit.c

OBJECTS = $(SRCS:.c=.o)

LIB = libft/libft.a

HEADER = -I .

CFLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -c $(SRCS) $(LIB) -I ./libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)

#%.o: %.c
#	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
