NAME=libft.a

SRCS=ft_bzero.c \
     ft_isalpha.c \
     ft_isdigit.c \
     ft_memset.c \
     ft_isalnum.c \
     ft_isascii.c \
     ft_isprint.c \
     ft_toupper.c \
     ft_tolower.c \
     ft_strchr.c \
     ft_strrchr.c \
     ft_strncmp.c \
     ft_memchr.c \
     ft_memcmp.c \
     ft_strnstr.c \
     ft_atoi.c \
     ft_strlcat.c \
     ft_strlcpy.c \
     ft_calloc.c \
     ft_strdup.c \
     ft_strlen.c \
     ft_bzero.c \
     ft_memcpy.c \
     ft_memmove.c \
     ft_substr.c \
     ft_strjoin.c \
     ft_strtrim.c \
     ft_split.c \
     ft_strmapi.c \
     ft_striteri.c \
     ft_putchar_fd.c \
     ft_putstr_fd.c \
     ft_putendl_fd.c \
     ft_putnbr_fd.c \
     ft_itoa.c \
     ft_putstr.c \
     get_next_line.c \
     ft_get_split_size.c \
     ft_free_split.c \
     ft_search_and_replace.c
     

OBJS = $(SRCS:.c=.o)

BSRCS=ft_lstnew.c \
      ft_lstadd_front.c \
      ft_lstsize.c \
      ft_lstlast.c \
      ft_lstadd_back.c \
      ft_lstdelone.c \
      ft_lstclear.c \
      ft_lstiter.c \
      ft_lstmap.c

BOBJECTS= $(BSRCS:.c=.o)

CC= cc
FLAGS= -g -Wall -Werror -Wextra

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(BOBJECTS)
	@ar rc $(NAME) $(OBJS) $(BOBJECTS)

all: $(NAME)

clean:
	@rm -f $(OBJS) $(BOBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

run: re
	@clear
	@$(CC) $(FLAGS) main.c $(NAME)
	@./a.out



run2: re
	@clear
	@$(CC) $(FLAGS) main.c $(NAME) -l bsd
	@./a.out

test: re
	@clear
	@bash run_docker.sh

t: re
	@clear
	@$(CC) main.c $(NAME) -l bsd
	@./a.out
