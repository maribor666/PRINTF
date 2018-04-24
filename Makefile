# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ospeka <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 16:23:53 by ospeka            #+#    #+#              #
#    Updated: 2018/04/19 16:23:54 by ospeka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_atoi.c \
		ft_count_num.c \
		ft_itoa.c \
		ft_putstr.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_itoabase.c \
		main.c \
		print_d.c \
		print_o.c \



OBJECTS = $(SRCS:.c=.o)


FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	
	ar rc $(NAME) $(OBJECTS) 

%.o: %.c
	gcc $(FLAGS) -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm  -f $(NAME)
	

re: fclean all
