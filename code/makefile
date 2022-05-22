NAME		= minishell
CC			= gcc
RM			= rm -f
SRCS		= minishell.c utils.c

all: $(NAME)

$(NAME): 
	$(CC) -o $(NAME) $(SRCS)

.PHONY : clean
clean:
				$(RM) $(NAME)

.PHONY : re
re:				clean
				make all