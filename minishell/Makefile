# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 16:42:11 by younjkim          #+#    #+#              #
#    Updated: 2022/06/07 18:40:02 by younjkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRC_DIR = srcs/
OBJ_DIR = objs/
LIB_DIR = libft/
LDFLAGS = -L/Users/younjkim/.brew/opt/readline/lib
CPPFLAGS = -I/Users/younjkim/.brew/opt/readline/include

INCS = -Iinc/ -I$(LIB_DIR) $(CPPFLAGS)
NAME = minishell

SRCS =	main.c \
		free.c \
		input.c \
		line.c \
		vars.c \
		redir_exec.c \

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR),$(OBJS))
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(INCS) $^ -o $(NAME) $(LDFLAGS) -lreadline -L$(LIB_DIR) -lft
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< $(INCS) -o $@
clean:
	$(RM) $(OBJ_DIR)
fclean: clean
	$(RM) $(NAME)
re: fclean all