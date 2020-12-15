/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** .h of lib
*/

#ifndef __MY_H__
#define __MY_H__
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#define A my_putchar('A');
char *my_strcpy_custom(char *dest, char const *src, char c);
int my_strlen_custom(char *str, char c);
int my_compute_factorial_it(int nb);
int my_compute_factorial_rec(int nb);
int my_compute_power_it(int nb, int p);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
char *my_evil_str(char *str);
int my_find_prime_sup(int nb);
int my_getnbr(char *str);
int my_isneg(int n);
int my_is_prime(int nb);
int my_print_alpha(void);
void print_comb2(int t1, int u1, int t2, int u2);
void my_print_comb2_alg(char t1, char u1, char t2, char u2);
int my_print_comb2(void);
void print_comb(char h, char t, char u);
int my_print_comb(void);
int compute_square(int x, int y);
int check_validity(int size, int nb);
int edge_ca(int nb, int original_i);
void print_comb_n(int nb, int size, int original_i);
int my_print_combn(int i);
int my_print_digits(void);
int my_print_revalpha(void);
int my_putchar(char c);
int how_many_char_in_str(char c, char const *str);
int base_check_and_len(char const *base);
int my_putnbr_base(int nbr, char const *base);
int edge_case(int nb);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
bool array_is_sort(int *array, int size);
void my_sort_int_array(int *array, int size);
int char_is_up(char c);
int char_is_low(char c);
int char_is_alphanum(char c);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char *str1, char *str2);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int char_is_num(char c);
int my_str_isnum(char const *str);
int char_is_printable(char c);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char *str1, char *str2, int n);
char *my_strncpy(char *dest, char const *src, int size);
int strcheck(char *str, char *to_find);
char *my_strstr(char *str, char *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
#endif
