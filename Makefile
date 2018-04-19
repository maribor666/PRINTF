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


all:
	gcc -c *.c libft/*.c -I libft/includes/
	ar rc libftprintf.a *.o
clean:
	rm *.o

fclean: clean
	rm libftprintf.a

re: fclean all
