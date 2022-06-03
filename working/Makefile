NAME =	minishell

SRCS_DIR = srcs/

SRCS =	$(SRCS_DIR)main.c \
			$(SRCS_DIR)utils.c \
			$(SRCS_DIR)utils_signal.c \
			$(SRCS_DIR)cd.c \
			$(SRCS_DIR)parser.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS += -fsanitize=address -lreadline

#-Wall -Werror -Wextra 

RM = rm -rf

LIBFT = libft.a
LIBFTDIR = libft/
LIBFTLINK = -L $(LIBFTDIR) -lft


all:		$(NAME)

$(NAME):	complib $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFTLINK)

complib:
	$(MAKE) -C libft/

%.o:		%.c
	$(CC) -c $(CFLAGS) -o $@ $<
	printf "$(GREEN)██"

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(OBJS)
	$(RM) $(NAME)

re:		fclean all

leaks:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

git:
	make fclean
	git add .
	git commit -m "make done"
	git push

norme:
	norminette ./srcs/* ./libft/*

.PHONY:		all clean fclean re leaks git norme
.SILENT:
