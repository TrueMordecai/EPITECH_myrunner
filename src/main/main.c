/*
** EPITECH PROJECT, 2020
** my_hunter main
** File description:
** start of the hunter
*/

#include "runner.h"

static void main_print_help_map_exemple(void)
{
    my_putstr("MAP_EXEMPLE\n\n");
    my_putstr("P     CCC  x   ***    V\n");
    my_putstr("ooooooooooooooooooooo\n");
    my_putstr(" ooooooooooooooooooo\n\n");
}

static void main_print_help_tag(void)
{
    my_putstr("    Different tag\n");
    my_putstr("        P - Spawn coordinate of the player\n");
    my_putstr("        * - Basic block, physical hitbox\n");
    my_putstr("        o - Block that change its texture depending the other ");
    my_putstr("'o' tag using a tileset, physical hitbox\n");
    my_putstr("        x - Spike that kill the player, physical hitbox\n");
    my_putstr("        > / < - Respectively speed up or speed down the player");
    my_putstr(" no physical hitbox\n");
    my_putstr("        w - Wall in the background, for decoration only, no ");
    my_putstr("physical hitbox\n");
    my_putstr("        J - Jumping orb, no physical hitbox\n");
    my_putstr("        C - Coin to collect, 3 pers map, no physical hitbox\n");
    my_putstr("        V - Victory portal. It algin with the player\n");
    my_putstr("        All other character a considered empty space\n\n");

}

static void main_print_other(void)
{
    my_putstr("KNOWN BUGS/WEIRDNESS\n");
    my_putstr("    'J' have an hitbox slightly smaller that you expect\n");
    my_putstr("    Hitbox of 'x' are square and not triangle\n");
    my_putstr("    Sometimes you might think that you should died, and its no");
    my_putstr("t a bug, i just make the hitbox generous\n");
    my_putstr("THE .H USED TO BE WELL DESCRIBED IN PREVIOUS COMMIT\n");
}

static int main_print_help(void)
{
    my_putstr("Finite runner made in csfml\n");
    my_putstr("Small recreation of Geometry Dash\n");
    my_putstr("When you launch the game you come to the intro");
    my_putstr("wich is only a way to pass the mandatory of the project\n\n");
    my_putstr("USAGE\n    ./my_runner [MAP_PATH]\n\n");
    my_putstr("USER INTERACTION\n");
    my_putstr("    spaceKey == Jump\n    escapeKey == Quit\n    rKey == Reset");
    my_putstr("\n    qKey == Go to intro\n    enterKey == Skip intro\n\n");
    my_putstr("HOW TO CREATE A MAP\n");
    my_putstr("    The mandatory\n        The file must end with a empty line");
    my_putstr("\n        The file must contain one and only one 'P' tag\n");
    my_putstr("        The file must contain 3 'C' tag\n");
    my_putstr("        The file must contain one 'V' tag placed at the very");
    my_putstr(" end of the map on any line, it will automatically align with");
    my_putstr(" the player\n");
    main_print_help_tag();
    main_print_help_map_exemple();
    main_print_other();
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
