NAME=	fdf

IMPORTS=	imports/
#GNL_PATH=	$(IMPORTS)get_next_line/
LIBFT_PATH=	$(IMPORTS)libft/

#GNL_A=		$(GNL_PATH)libgnl.a
LIBFT_A=	$(LIBFT_PATH)libft.a

CC=		cc
CFLAGS=	-g -Wall -Werror -Wextra
INCLUDE= includes

SRCS=	fdf.c \
		srcs/parse/map_lines.c \
		srcs/parse/map_pointer.c \
		srcs/parse/map_control.c \
		srcs/parse/map_build.c \
		srcs/parse/parser.c

OBJS=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(GNL_A)
#	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -L$(GNL_PATH) -lgnl -o $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

# $(GNL_A):
# 	@make -C $(GNL_PATH)

$(LIBFT_A):
	@make -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJS)

fclean: clean
#	@make fclean -C $(GNL_PATH)
	@make fclean -C $(LIBFT_PATH)
	@rm -rf $(NAME)

r: $(NAME)
	@clear
	@./$(NAME) ./test.txt

c: fclean $(NAME)

# $(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)