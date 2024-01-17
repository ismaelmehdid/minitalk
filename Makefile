# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 22:01:52 by ismaelmehdi       #+#    #+#              #
#    Updated: 2024/01/17 15:44:48 by ismaelmehdi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server

SRCS = server.c
SRCC = client.c

OBJS = ${SRCS:.c=.o}
OBJC = ${SRCC:.c=.o}

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -Iincludes

RM = rm -f

all: ${NAMEC} ${NAMES}

$(NAMEC): ${OBJC}
		@${MAKE} -C ./libft
		@${MAKE} -C ./printf
		@${CC} ${CFLAGS} ${OBJC} ./libft/libft.a ./printf/libftprintf.a -o ${NAMEC}

$(NAMES): ${OBJS}
		@${MAKE} -C ./libft
		@${MAKE} -C ./printf
		@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a ./printf/libftprintf.a -o ${NAMES}

clean:
		@${MAKE} -C ./libft fclean
		@${MAKE} -C ./printf fclean
		@${RM} ${OBJS} ${OBJC}

fclean: clean
		@${RM} ${OBJS} ${OBJC} ${NAMEC} ${NAMES}

re: fclean all

.PHONY: all clean fclean re