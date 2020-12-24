/*
** EPITECH PROJECT, 2020
** my_hunter main
** File description:
** start of the hunter
*/

#include "runner.h"

static void main_print_help_map_exemple()
{
    my_putstr("MAP_EXEMPLE\n\n");
    my_putstr("P       x   ***\n");
    my_putstr("ooooooooooooooooooooo\n");
    my_putstr(" ooooooooooooooooooo\n\n");
}

static int main_print_help()
{
    my_putstr("Finite runner made in csfml\n");
    my_putstr("Small recreation of Geometry Dash\n\n");
    my_putstr("USAGE\n    ./my_runner [MAP_PATH]\n\n");
    my_putstr("USER INTERACTION\n");
    my_putstr("    spaceKey == jump\n    qKey == quit\n    rKey == reset\n\n");
    my_putstr("HOW TO CREATE A MAP\n");
    my_putstr("    The mandatory\n        The file must end with a empty line");
    my_putstr("\n        The file must contain one and only one 'P' tag\n");
    my_putstr("    Different tag\n");
    my_putstr("        P - Spawn coordinate of the player.\n");
    my_putstr("        * - Basic block, physical hitbox.\n");
    my_putstr("        o - Block that change its texture depending where is i");
    my_putstr("t using a tileset, physical hitbox\n");
    my_putstr("        x - Spike that kill the player, physical hitbox\n");
    my_putstr("        > / < - Respectively speed up or speed down the player");
    my_putstr(" no physical hitbox\n");
    my_putstr("        w - Wall in the background, for decoration only, no ");
    my_putstr("physical hitbox\n");
    my_putstr("        All other character a considered empty space\n");
    main_print_help_map_exemple();
    return (0);
}

int main(int ac, char **av)
{
    srand(time(NULL));
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && my_strlen(av[1]) == 2)
        return (main_print_help());
    if (main_loop(av[1]) == 0) {
        my_putstr("Something went wrong during initialization.\n");
        return (84);
    }
    return (0);
}
