/*
** EPITECH PROJECT, 2020
** my_putnbr_base
** File description:
** put nbr base
*/

int my_putchar(char c);

int how_many_char_in_str(char c, char const *str)
{
    int occu = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            occu++;
    }
    return (occu);
}

int base_check_and_len(char const *base)
{
    int i = 0;

    while (base[i] != '\0') {
        if (how_many_char_in_str(base[i], base) > 1)
            return (-1);
        i++;
    }
    return (i);
}

int my_putnbr_base(int nbr, char const *base)
{
    int len = base_check_and_len(base);

    if (len == -1)
        return (0);
    if (nbr < len) {
        my_putchar(base[nbr]);
    } else {
        my_putnbr_base(nbr / len, base);
        my_putchar(base[nbr % len]);
    }
    return (1);
}
