CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
NAME = push_swap
INC_PATH = includes/

SRC =	./srcs/push_swap.c \
		./srcs/lst_management.c \
		./srcs/parsing.c \
		./srcs/sort_part1.c \
		./srcs/sort_part2.c \
		./srcs/move_up.c \
		./srcs/utils.c \
		./srcs/push.c \
		./srcs/swap.c \
		./srcs/rotate.c \
		./srcs/r_rotate.c \

OBJ = $(SRC:.c=.o)
INCLUDES = push_swap.h

LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $^ -I $(INC_PATH) -L ./libft -lft -o push_swap
$(OBJ) : $(INC_PATH)$(INCLUDES)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)
clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

test : $(NAME)
	echo "" && ./a.out && echo ""

.PHONY : all fclean clean re exec test