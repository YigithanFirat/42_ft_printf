NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = format_type.c \
	   ft_printf.c \
	   ft_putchar.c \
	   ft_puthex.c \
	   ft_putnbr.c \
	   ft_putptr.c \
	   ft_putstr.c \
	   ft_putunsign.c \

OBJS = $(SRCS:.c=.o)

all = $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
