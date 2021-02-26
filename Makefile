##
## ETNA PROJECT, 15/01/2021 by dousse_r
## /home/slowiizz/Documents/group-843271
## File description:
##      makefile du projet
##

CC		= 	gcc
CFLAGS	=	-Wall -Wextra -Werror -I./include
NAME	=	my_ls
SRC		= 	./sources/my_ls.c	\
			./sources/libmy/my_putchar.c \
			./sources/libmy/my_putnbr.c \
			./sources/libmy/my_putstr.c \
			./sources/libmy/my_strcat.c \
			./sources/libmy/my_strcmp.c \
			./sources/libmy/my_strcpy.c \
			./sources/libmy/my_strdup.c \
			./sources/libmy/my_strlen.c \
			./sources/malloc_free.c	\
			./sources/my_print.c	\
			./sources/sorting.c \
			./sources/command.c	\
			./sources/my_modes.c	\

OBJ		=	$(SRC:%.c=%.o)
RM		=	rm -f

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
all:			$(NAME)
clean:
				$(RM) $(OBJ)
fclean:			clean
				$(RM) $(NAME)
re:	fclean all