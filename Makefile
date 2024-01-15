# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 22:01:52 by ismaelmehdi       #+#    #+#              #
#    Updated: 2024/01/15 22:25:06 by ismaelmehdi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server

SRCS = ${wildcard *.c}
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -Iincludes

RM = rm -f

all: ${NAMEC} ${NAMES}

$(NAMEC): ${OBJS}
		@${MAKE} -C ./libft
		@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAMEC}

$(NAMES): ${OBJS}
		@${MAKE} -C ./libft
		@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAMES}

clean:
		@${MAKE} -C ./libft fclean
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${OBJS} ${NAMEC} ${NAMES}

re: fclean all

.PHONY: all clean fclean re