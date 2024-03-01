# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbousset <cbousset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 09:24:51 by cbousset          #+#    #+#              #
#    Updated: 2024/03/01 17:03:06 by cbousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = cc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror
NAME = myLib.a

FILES = $(wildcard *.c)
		
SRCS		= $(FILES)
	
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	ar rc $(NAME) $(OBJS)
 
.c.o: $(SRCS) myLib.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
