##
## EPITECH PROJECT, 2019
## epi
## File description:
## Makefile
##

NAME		=		my_runner

SRC			=		src/main/main.c								\
					src/initialization/core_init.c				\
					src/initialization/game_init.c				\
					src/initialization/player_init.c			\
					src/initialization/map_init.c				\
					src/initialization/map_info_init.c			\
					src/initialization/input_init.c				\
					src/initialization/background_init.c		\
					src/game_loop/main_loop.c					\
					src/tool/tool_func.c

OBJ			=		$(SRC:%c=%o)

CC			=		gcc

CFLAGS		=		-I./include -W -Wall -Wextra -pedantic -Wshadow

LDFLAGS		=		-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lmy -L./lib

$(NAME)		:		$(OBJ)
					make -C ./lib
					$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

all			:		$(NAME)

clean		:
					rm -f $(OBJ)
					make -C ./lib fclean

fclean		:		clean
					make -C ./lib fclean
					rm -f $(NAME)

debug		:		CFLAGS += -g
debug		:		re

re 			:		fclean all
