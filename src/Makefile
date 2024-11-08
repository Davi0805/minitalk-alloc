MAKEFLAGS += -s

NAME = libft.a
CC = cc
LIBFTNAME = libftprintf.a
LIBFTDIR = ../print_functions
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
SRCS = server.c client.c utils.c\

GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
NC = \033[0m

all: mandatory

$(NAME): $(LIBFTDIR)/$(LIBFTNAME)
	@cp $(LIBFTDIR)/$(LIBFTNAME) $(NAME)

$(LIBFTDIR)/$(LIBFTNAME):
	@make -C $(LIBFTDIR)

mandatory: $(NAME) $(OBJS)
	@echo "# $(GREEN)Building project...$(NC)"
	@$(CC) $(FLAGS) -o client client.o utils.o $(NAME)
	@$(CC) $(FLAGS) -o server server.o utils.o $(NAME)
	@echo "$(GREEN)Done!$(NC)"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f *.o
	@cd $(LIBFTDIR) && make clean
	@echo "# $(YELLOW)Cleaning...$(NC)"

fclean: clean
	@rm -rf $(NAME)
	@rm -f client
	@rm -f server
	@cd $(LIBFTDIR) && make fclean
	@echo "# $(RED)Fully Cleaned!$(NC)"

re: fclean all

.PHONY: all clean fclean re
