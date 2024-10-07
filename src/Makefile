NAME = libft.a
CC = cc
LIBFTNAME = libftprintf.a
LIBFTDIR = ../print_functions
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
SRCS = utils.c \

all: client server

$(NAME): $(LIBFTDIR)/$(LIBFTNAME)
		cp $(LIBFTDIR)/$(LIBFTNAME) $(NAME)

$(LIBFTDIR)/$(LIBFTNAME):
		make -C $(LIBFTDIR)

server: $(NAME) server.o $(OBJS)
		$(CC) $(FLAGS) server.o -o server $(OBJS) $(NAME)

client: $(NAME) client.o $(OBJS)
		$(CC) $(FLAGS) client.o -o client $(OBJS) $(NAME)

client_bonus: $(NAME) client_bonus.o $(OBJS)
		$(CC) $(FLAGS) client_bonus.o -o client_bonus $(OBJS) $(NAME)

server_bonus: $(NAME) server_bonus.o $(OBJS)
		$(CC) $(FLAGS) server_bonus.o -o server_bonus $(OBJS) $(NAME)

bonus: $(NAME) server_bonus client_bonus $(OBJS)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

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
