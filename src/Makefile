NAME = libft.a
CC = cc
LIBFTNAME = libftprintf.a
LIBFTDIR = ../print_functions
FLAGS = -Wall -Wextra -Werror

SRCS = utils.c \

all: $(NAME)

makelibft:
		make -C $(LIBFTDIR)
		cp $(LIBFTDIR)/$(LIBFTNAME) .
		mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft
		$(CC) client.c -o client $(SRCS) $(NAME)
		$(CC) server.c -o server $(SRCS) $(NAME)

clean:
	rm -f *.o
	cd $(LIBFTDIR) && make clean

fclean: clean
	rm -rf $(NAME)
	rm -f client
	rm -f server
	cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
