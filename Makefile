SRCS		=	check_args.c	\
				main.c	\
				make_char_arry.c	\
				scan_num.c

OBJS		=	$(SRCS:%.c=%.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	push_swap
LIBFTDIR	=	libft
LIBFT		=	$(LIBFTDIR)/libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBFTDIR)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:		
			make fclean -C libft
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
