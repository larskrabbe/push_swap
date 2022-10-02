
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
		checkers.c\
		free_stack.c\
		chunksort.c\
		quicksort.c

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

#ARG = "954649438 -1184622453 204402658 -1061102961 1288341240"
#ARG = "4 0 3 1 2"
#455110993 164502198 154875247 1088263319 1969608996
ARG = "4 2 1 0 3 5 9 8 7 6 10 11 18 19 15 16 17 14 13 12"
test:all
		./push_swap $(ARG)
		./push_swap $(ARG) | wc -l
		./push_swap $(ARG) | ./checker_MAC $(ARG)
testb:all
				./push_swap  1 2 3 5 4 12 -8 9 9999
re : fclean all

.phony: all re clean fclean 