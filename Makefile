SRCS	=	algo.c	basic_moves1.c	basic_moves2.c	lst_utils.c	\
			optimization.c	push_swap.c	test.c	utils1.c \
			utils2.c	error_managment.c
		
OBJS	=	$(SRCS:.c=.o)

NAME	=	push_swap

CC		=	gcc

CFLAG	=	-Wall -Wextra -Werror -O3

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