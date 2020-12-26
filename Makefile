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
					src/initialization/hud_init.c				\
					src/initialization/error/error_on_map.c		\
					src/game_loop/main_loop.c					\
					src/game_loop/special_block.c				\
					src/game_loop/display/map_display.c			\
					src/game_loop/display/player_display.c		\
					src/game_loop/display/background_display.c	\
					src/game_loop/input/input.c					\
					src/tool/tool_func.c						\
					src/tool/bool_check_state.c

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
