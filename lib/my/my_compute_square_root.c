/*
** EPITECH PROJECT, 2020
** compute square root
** File description:
** find square root
*/

int my_compute_power_it(int nb, int p);

int my_compute_square_root(int nb)
{
    int i = 0;

    while (my_compute_power_it(i, 2) != nb) {
        if (i > nb / 2)
            return (0);
        i++;
    }
    return (i);
}
