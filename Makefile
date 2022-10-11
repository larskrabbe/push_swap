
VPATH = src

NAME = push_swap

CC = cc

CFLAGS = -Werror -Wextra -Wall # -D BETTERERROR=1 #-fsanitize=address -static-libsan

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
ARG = "2 1 3 6 5 8 "
test:all
		./push_swap $(ARG)
		./push_swap $(ARG) | wc -l
		./push_swap $(ARG) | ./checker_MAC $(ARG)
testb:all
				./push_swap  "-2147483649"
re : fclean all

.phony: all re clean fclean 