NAME = push_swap

SRCS = 0-push_swap.c \
	   libft1.c \
	   libft2.c \
	   libft3.c \
	   1-linked_list_add.c \
	   1-linked_list_remove.c \
	   1-general_operations.c \
	   2-operations_1.c \
	   2-operations_2.c \
	   2-operations_3.c \
	   3-sorting_1.c \
	   3-sorting_2.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
