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

bonus: $(NAME)
	$(CC) client_bonus.c -o client_bonus $(SRCS) $(NAME)
	$(CC) server_bonus.c -o server_bonus $(SRCS) $(NAME)

clean:
	rm -f *.o
	cd $(LIBFTDIR) && make clean

fclean: clean
	rm -rf $(NAME)
	rm -f client client_bonus
	rm -f server server_bonus
	cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
