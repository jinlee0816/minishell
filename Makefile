# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinwolee <jinwolee@42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 14:36:30 by jinwolee          #+#    #+#              #
#    Updated: 2022/05/26 14:39:11 by jinwolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = ./srcs

SRCS =	$(SRCS_DIR)/main.c \
		$(SRCS_DIR)/cd.c \
		$(SRCS_DIR)/command.c \
		$(SRCS_DIR)/export.c \
		$(SRCS_DIR)/pwd.c \
		$(SRCS_DIR)/utils_len.c \
		$(SRCS_DIR)/utils.c

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