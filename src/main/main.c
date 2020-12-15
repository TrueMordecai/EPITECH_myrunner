/*
** EPITECH PROJECT, 2020
** my_hunter main
** File description:
** start of the hunter
*/

#include "runner.h"

static int main_print_help()
{
    my_putstr("The goal of the game is to find the right head in the limited ");
    my_putstr("timer.\nThere is 3 type of round : ghost, statue and bounce\n");
    my_putstr("And they each have a alternatve versions\n");
    my_putstr("Good luck :D!\n");
    return (0);
}

int main(int ac, char **av)
{
    srand(time(NULL));
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && my_strlen(av[1]) == 2)
        return (main_print_help());
    main_loop();
}
