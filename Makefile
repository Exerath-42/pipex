NAME = pipex

HEADER = pipex.h

SRCS = main.c pipex_utils.c ft_split.c other_utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Werror -Wextra -Wall

all:		$(NAME)

%.o: %.c	$(HEADER)
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(HEADER)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

clean:		
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re