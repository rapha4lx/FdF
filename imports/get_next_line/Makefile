NAME=	libgnl.a

SRCS=	get_next_line.c \
     	get_next_line_utils.c

OBJS=	$(SRCS:.c=.o)

CC=		cc
FLAGS=	-Wall -Werror -Wextra

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	@rm -f $(OBJS) $(BOBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)