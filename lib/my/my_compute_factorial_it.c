/*
** EPITECH PROJECT, 2020
** my_compute_factorial_it
** File description:
** return the factorial
*/

int my_compute_factorial_it(int nb)
{
    int i = 1;
    int res = 1;

    if (nb == 0)
        return (1);
    if (nb < 0 || nb > 12)
        return (0);
    while (i != nb + 1) {
        res *= i;
        i++;
    }
    if (res < 0)
        return (0);
    return (res);
}
