NAME = 	philo_two

SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
INCS_PATH = ./includes/

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))
OBJS = $(addprefix $(OBJS_PATH),$(OBJS_NAME))

OBJS_NAME = $(SRCS_NAME:.c=.o)

SRCS_NAME = clear.c init.c main.c messages.c monitoring.c time.c utils2.c utils.c

CC = gcc

FLAGS =	-Wall -Werror -Wextra

all: 			$(NAME)

$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(FLAGS) $(OBJS) -lpthread
		@echo "\033[0;34mExecutable philo_two \033[0m \033[0;32m [OK] \033[0m"
		
$(OBJS_PATH)%.o: $(SRCS_PATH)%.c includes/philos.h
		@mkdir -p $(OBJS_PATH)
		@gcc $(FLAGS) $(INCS) -o $@ -c $<

run : 
		make re
		./$(NAME)

clean:
		@rm -rf $(OBJS_PATH)
		@echo "deleted ./objs/"

fclean: clean
		@rm -rf $(NAME)
		@echo "deleted ./philo_two"

re: fclean all


.PHONY:			all clean fclean re