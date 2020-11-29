##
## EPITECH PROJECT, 2020
## Day10
## File description:
## Makefile
##

SRC	=	$(wildcard lib/my/*.c)

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

SRCP	=	./*.c \
			./src/*.c

CFLAGS	=	-o $(PRJ) -I./include -L./lib/my/ -lmy -L/usr/include/SFML -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

PRJ	=	my_hunter

LIB	=	libmy.a

all:	lib	compile

lib:	$(OBJ)
	ar rsc $(LIB) $(OBJ)
	cp ./$(LIB) lib/
	mv ./$(LIB)	lib/my/
	cp lib/my/my.h include/
	make clean

compile:
	rm -f $(PRJ)
	$(CC) $(SRCP) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f lib/$(LIB)
	rm -f lib/my/$(LIB)
	rm -f include/my.h
	rm -f $(PRJ)

re:	fclean all