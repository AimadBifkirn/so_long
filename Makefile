 
NAME = so_long
OBJ = so_long.o add_node.o check_functions.o free_images.o ft_itoa.o get_next_line_utils.o \
	 initialize_struct.o is_wall_line.o window_checks.o allocate_images.o flood_fill.o \
	 free_struct.o get_next_line.o hook_functions.o initialize_with_0.o print_functions.o utils.o window_work.o
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lmlx -lX11 -lXext

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJ) $(BOBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
