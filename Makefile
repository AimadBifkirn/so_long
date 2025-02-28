 
NAME = push_swap
OBJ = so_long.o add_node.o check_functions.o free_images.o ft_itoa.o ft_strcmp.o \
	 ft_split.o ft_atoi.o doubles_check.o sort_stack.o sorted_check.o strlen_memcpy.o \
	 big_sort.o arry.o
CC = cc
CFLAGS = -Wall -Wextra -Werror -lmlx -lX11 -lXext

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




#	cc *.c -lmlx -lX11 -lXext