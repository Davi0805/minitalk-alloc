MAKEFLAGS += -s

NAME = libft.a
CC = cc
LIBFTNAME = libftprintf.a
LIBFTDIR = ../print_functions
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
SRCS = server.c client.c utils.c
BONUS_SRCS = server_bonus.c client_bonus.c utils_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)


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
	@$(CC) $(FLAGS) -fsanitize=undefined -o client client.o utils.o $(NAME)
	@$(CC) $(FLAGS) -fsanitize=undefined -o server server.o utils.o $(NAME)
	@echo "$(GREEN)Done!$(NC)"

bonus: $(NAME) $(BONUS_OBJS)
	@echo "# $(GREEN)Building project...$(NC)"
	@$(CC) $(FLAGS) -fsanitize=undefined -o client client_bonus.o utils.o $(NAME)
	@$(CC) $(FLAGS) -fsanitize=undefined -o server server_bonus.o utils.o $(NAME)
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
