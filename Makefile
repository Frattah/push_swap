SRCS	=	decision_table.c	basic_moves1.c	basic_moves2.c	lst_utils.c	\
			optimization.c	push_swap.c	utils1.c utils2.c	main.c	\

OBJS	=	$(SRCS:.c=.o)

NAME	=	push_swap

CC		=	gcc

CFLAG	=	-Wall -Werror -Wextra -O3

all: $(NAME) 

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME):  $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean all clean
