# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 16:42:11 by younjkim          #+#    #+#              #
#    Updated: 2022/05/22 19:19:15 by younjkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		free.c \
		signal/signal_util.c \

OBJS = ${SRCS:.c=.o}

NAME = minishell

HEADER = minishell.h

CC = clang

CFLAGS = -Wall -Werror -Wextra 
RM = rm -f

.c.o:
	${CC} -c ${CFLAGS} -I -L./libft/ -o $@ $<

$(NAME):    ${OBJS}
		make -C libft
		${CC} ${CFLAGS} ${OBJS} -I -L./libft/ -lreadline -lm ./libft/libft.a -o ${NAME}

all:	${NAME}

clean:
	make clean -C libft
	${RM} ${OBJS}

fclean: clean
	make fclean -C libft
	${RM} ${NAME}

re:	 fclean all

.PHONY: all clean fclean re