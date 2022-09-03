NAME    = push_swap
LIBFT   = libft.a
PRINTF  = libftprintf.a
HEADER  = ./includes/header_push_swap.h
OBJS_DIR = objs/
SRC = $(wildcard ./format_parsing/*.c) \
		$(wildcard ./helpers/*.c) \
	 	$(wildcard ./push_swaph/*.c)
OBJS = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME) : $(LIBFT) $(PRINTF) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(LIBFT) :
	@cd ./libft && make

$(PRINTF) :
	@cd ./ft_printf/ && make

# $(OBJS_DIR)%.o : $(SRC)
# 	@mkdir -p $(OBJS_DIR)
# 	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS_DIR)
	@rm -f $(OBJS)

fclean : clean
	@rm -rf $(OBJS)
	@cd ./libft/ && make fclean
	@cd ./ft_printf/ && make fclean

	