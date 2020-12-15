/*
** EPITECH PROJECT, 2020
** my_compute_power_it
** File description:
** compute power it
*/

int my_compute_power_it(int nb, int p)
{
    int i = 0;
    int res = 1;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    while (i != p) {
        res *= nb;
        i++;
    }
    return (res);
}
