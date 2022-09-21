
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
		swap.c

OBJ = $(SRC:.c=.o) $(F_LIBFT_PLUS:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ 

all : $(LIBFT_LIB) $(OBJ)
	@echo	"\033[0;32m compiling client\n\033[0m"
	$(CC) $(OBJ) $(LIBFT_FLAGS) -o $(NAME)

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

test:all
		./push_swap 1 3 4 2416 351 5 2 5878 1315 2134

re : fclean all

.phony: all re clean fclean 