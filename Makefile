MAIN	=	main.c

SRCS	=	decision_table.c	basic_moves1.c	basic_moves2.c	lst_utils.c	\
			optimization.c	push_swap.c	utils1.c utils2.c	\

BMAIN	=	checker.c

OBJS	=	$(SRCS:.c=.o)

OMAIN	=	$(MAIN:.c=.o)

BOMAIN	=	$(BMAIN:.c=.o)

NAME	=	push_swap

BNAME	=	checker

CC		=	gcc

CFLAG	=	-O3 -w

all: $(NAME) 

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME):  $(OBJS) $(OMAIN)
	$(CC) $(CFLAG) $(OBJS) $(OMAIN) -o $(NAME)

clean:
	rm -rf $(OBJS) $(OMAIN) $(BOMAIN)

fclean: clean
	rm -rf $(NAME) $(BNAME)

re: fclean all

bonus:	$(BNAME)

$(BNAME): $(OBJS) $(BOMAIN)
	$(CC) $(CFLAG) $(OBJS) $(BOMAIN) -o $(BNAME)

.PHONY: re fclean all clean bonus
