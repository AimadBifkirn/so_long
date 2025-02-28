NAME = push_swap
OBJ = push_swap.o OP-swap_push.o OP-rotate.o OP-reverse_rotate.o len_stack.o \
	 ft_split.o ft_atoi.o doubles_check.o sort_stack.o sorted_check.o strlen_memcpy.o \
	 big_sort.o arry.o
BOBJ = ./bonus/push_swap_bonus.o ./bonus/OP-swap_push_bonus.o ./bonus/OP-rotate_bonus.o \
	 ./bonus/OP-reverse_rotate_bonus.o len_stack.o ft_split.o ft_atoi.o doubles_check.o \
	 sorted_check.o strlen_memcpy.o ./bonus/execute_op_bonus.o ./bonus/get_next_line_bonus.o \
	 ./bonus/get_next_line_utils_bonus.o
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus :  checker

checker : $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -o checker

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJ) $(BOBJ)

fclean : clean
	rm -f $(NAME) checker

re : fclean all
