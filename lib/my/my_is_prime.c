/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** check if prime
*/

int my_is_prime(int nb)
{
    int i = 2;
    int max_value = nb;

    if (nb > 100)
        max_value /= 2;
    if (nb <= 1)
        return (0);
    while (i != max_value) {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}
