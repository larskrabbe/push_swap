
VPATH = src

NAME = push_swap

CC = cc

CFLAGS = -Werror -Wextra -Wall

LIBFT_FLAGS = -Llib -lft

F_LIBFT = libft/

LIBFT_LIB = libft.a

SRC = push_swap.c \
		utiels.c\
		stack_creation.c\
		push.c\
		swap.c\
		rotate.c\
		rules.c\
		sorting.c\
		checkers.c

OBJ = $(SRC:.c=.o) $(F_LIBFT_PLUS:.c=.o) 

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o  $@ 

all : $(LIBFT_LIB) $(OBJ)
	@echo	"\033[0;32m compiling push_swap\n\033[0m"
	$(CC) $(OBJ) $(LIBFT_FLAGS) -o $(NAME)
	@echo	"\033[0;32m compiling finished\n\033[0m"

$(LIBFT_LIB):
	# @$(MAKE) -C $(F_LIBFT)
	# @mv $(F_LIBFT)$(LIBFT_LIB) lib

clean :
		@echo	"\033[1;31m"
		rm -f *.o
		@echo	"\033[0;0m"

fclean : clean 
		@echo	"\033[1;31m"
		rm -f $(NAME)
		@echo	"\033[0;0m"

ARG = " 1 4 2 3 5"
test:all
		./push_swap $(ARG)
		./push_swap $(ARG) | wc -l
		./push_swap $(ARG) | ./checker_MAC $(ARG)
testb:all
				./push_swap  1 2 3 5 4 12 -8 9 9999
re : fclean all

.phony: all re clean fclean 