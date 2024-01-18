# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 22:01:52 by ismaelmehdi       #+#    #+#              #
#    Updated: 2024/01/18 18:57:18 by ismaelmehdi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server

NAMEC_BONUS = client_bonus
NAMES_BONUS = server_bonus

SRCS = mandatory/server.c
SRCC = mandatory/client.c

SRCS_BONUS = bonus/server_bonus.c
SRCC_BONUS = bonus/client_bonus.c

OBJS = ${SRCS:.c=.o}
OBJC = ${SRCC:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}
OBJC_BONUS = ${SRCC_BONUS:.c=.o}

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

$(NAMEC_BONUS): ${OBJC_BONUS}
		@${MAKE} -C ./libft
		@${MAKE} -C ./printf
		@${CC} ${CFLAGS} ${OBJC_BONUS} ./libft/libft.a ./printf/libftprintf.a -o ${NAMEC_BONUS}

$(NAMES_BONUS): ${OBJS_BONUS}
		@${MAKE} -C ./libft
		@${MAKE} -C ./printf
		@${CC} ${CFLAGS} ${OBJS_BONUS} ./libft/libft.a ./printf/libftprintf.a -o ${NAMES_BONUS}

clean:
		@${MAKE} -C ./libft fclean
		@${MAKE} -C ./printf fclean
		@${RM} ${OBJS} ${OBJC}
		@${RM} ${OBJS_BONUS} ${OBJC_BONUS}

fclean: clean
		@${RM} ${OBJS} ${OBJC} ${NAMEC} ${NAMES}
		@${RM} ${OBJS_BONUS} ${OBJC_BONUS} ${NAMEC_BONUS} ${NAMES_BONUS}

re: fclean all

bonus: $(NAMES_BONUS) $(NAMEC_BONUS)

.PHONY: all clean fclean re