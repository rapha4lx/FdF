NAME=	fdf

IMPORTS=	imports/
LIBFT_PATH=	$(IMPORTS)libft/
MINILIB_PATH= $(IMPORTS)minilibx-linux/

LIBFT_A=	$(LIBFT_PATH)libft.a
MINILIB_A= 	$(MINILIB_PATH)libmlx.a

CC=		cc
CFLAGS=	-g -Wall -Werror -Wextra
INCLUDE= includes

SRCS=	fdf.c \
		srcs/parse/map_lines.c \
		srcs/parse/map_pointer.c \
		srcs/parse/map_control.c \
		srcs/parse/map_build.c \
		srcs/parse/parser.c \
		srcs/graphic/init_window.c \
		srcs/graphic/init_hook.c \
		srcs/hooks/keyboard_event.c \
		srcs/hooks/mouse_events.c \
		srcs/graphic/render.c \
		srcs/graphic/graphic_math.c \
		srcs/graphic/clear_pixels.c \
		srcs/graphic/image.c


OBJS=	$(SRCS:.c=.o)

all: $(MINILIB_A) $(LIBFT_A) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_PATH) -lft -L $(MINILIB_PATH) -lmlx -lX11 -lXext -lft -lm -lz -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(MINILIB_A):
	@make -C $(MINILIB_PATH)

$(LIBFT_A):
	@make -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@make clean -C $(MINILIB_PATH)
	@rm -rf $(NAME)

r: $(NAME)
	@clear
	@./$(NAME) ./test.txt

c: fclean $(NAME)
