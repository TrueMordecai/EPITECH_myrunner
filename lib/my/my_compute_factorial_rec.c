/*
** EPITECH PROJECT, 2020
** my_compute_factorial_rec
** File description:
** compute rec
*/

int my_compute_factorial_rec(int nb)
{
    if (nb > 12 || nb < 0)
        return (0);
    if (nb == 1 || nb == 0)
        return (1);
    return (nb * my_compute_factorial_rec(nb - 1));
}
