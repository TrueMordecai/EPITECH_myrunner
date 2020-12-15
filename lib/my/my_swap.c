/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** change two integer
*/

void my_swap(int *a, int *b)
{
    int pivot = *a;

    *a = *b;
    *b = pivot;
}
