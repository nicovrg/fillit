# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 16:29:08 by nivergne          #+#    #+#              #
#    Updated: 2018/11/13 16:00:51 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_atoi.c\
		ft_isprint.c\
		ft_lstmap.c\
		ft_memcpy.c\
		ft_putendl.c\
		ft_strcat.c\
		ft_strdup.c\
		ft_strlen.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_bzero.c\
		ft_itoa.c\
		ft_lstnew.c\
		ft_memdel.c\
		ft_putendl_fd.c\
		ft_strchr.c\
		ft_strequ.c\
		ft_strmap.c\
		ft_strnew.c\
		ft_strtrim.c\
		ft_isalnum.c\
		ft_lstadd.c\
		ft_memalloc.c\
		ft_memmove.c\
		ft_putnbr.c\
		ft_strclr.c\
		ft_striter.c\
		ft_strmapi.c\
		ft_strrchr.c\
		ft_swap.c\
		ft_isalpha.c\
		ft_lstdel.c\
		ft_memccpy.c\
		ft_memset.c\
		ft_putnbr_fd.c\
		ft_strcmp.c\
		ft_striteri.c\
		ft_strncat.c\
		ft_strrev.c\
		ft_tolower.c\
		ft_isascii.c\
		ft_lstdelone.c\
		ft_memchr.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_strcpy.c\
		ft_strjoin.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strsplit.c\
		ft_toupper.c\
		ft_isdigit.c\
		ft_lstiter.c\
		ft_memcmp.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_strdel.c\
		ft_strlcat.c\
		ft_strncpy.c\
		ft_strstr.c

OBJECTS = $(SRCS:.c=.o)

HEADER = -I .

CFLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean

#test: coucou
#	echo $< # coucou = c'est la dependance
#	echo $@ # test = c'est la regle