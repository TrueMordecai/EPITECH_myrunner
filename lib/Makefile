##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Lib Makefile
##

SRC		=	my/my_compute_factorial_it.c         	\
			my/my_compute_factorial_rec.c         	\
			my/my_compute_power_it.c            	\
			my/my_compute_power_rec.c            	\
			my/my_compute_square_root.c            	\
			my/my_evil_str.c            			\
			my/my_find_prime_sup.c            		\
			my/my_getnbr.c            				\
			my/my_isneg.c            				\
			my/my_is_prime.c            			\
			my/my_print_alpha.c            			\
			my/my_print_comb2.c            			\
			my/my_print_comb.c            			\
			my/my_print_combn.c           	 		\
			my/my_print_digits.c          			\
			my/my_print_revalpha.c           		\
			my/my_putchar.c            				\
			my/my_putnbr_base.c            			\
			my/my_put_nbr.c            				\
			my/my_putstr.c            				\
			my/my_revstr.c            				\
			my/my_showmem.c            				\
			my/my_showstr.c            				\
			my/my_sort_int_array.c            		\
			my/my_strcapitalize.c            		\
			my/my_strcat.c            				\
			my/my_strcmp.c         					\
			my/my_strcpy.c         					\
			my/my_str_isalpha.c            			\
			my/my_str_islower.c            			\
			my/my_str_isnum.c         				\
			my/my_str_isprintable.c            		\
			my/my_str_isupper.c            			\
			my/my_strlen.c         					\
			my/my_strlowcase.c         				\
			my/my_strncat.c            				\
			my/my_strncmp.c            				\
			my/my_strncpy.c            				\
			my/my_strstr.c         					\
			my/my_strupcase.c          				\
			my/my_swap.c


OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

INCLUDE = 	-I./include

CC 		= 	gcc

COMP	= 	ar rc

CFLAGS	=	-Wall -Wshadow  -L.

all:		$(NAME)

$(NAME):	$(OBJ)
		$(COMP) $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

