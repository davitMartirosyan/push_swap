NAME = push_swap
LIBFT = ./libft/libft.a
PRINTF  = ./ft_printf/libftprintf.a

LIBFT_ARCHIVE = libft.a
PRINTF_ARCHIVE = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
CC = cc

HEADER = includes/header_push_swap.h
SRC = $(wildcard ./format_parsing/*.c) $(wildcard ./helpers/*.c) $(wildcard ./push_swaph/*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))


all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT_ARCHIVE) $(PRINTF_ARCHIVE)
	@$(CC)  $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT_ARCHIVE) :
	@cd ./libft && make

$(PRINTF_ARCHIVE) :
	@cd ./ft_printf && make

%.o : %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

re : fclean all

clean :
	@rm -rf $(OBJ)
	@cd ./libft && make clean
	@cd ./ft_printf && make clean

fclean : clean
	@rm $(NAME)
	@cd ./libft/ && make fclean
	@cd ./ft_printf/ && make fclean

.PHONY: clean all re fclean
