/*
** EPITECH PROJECT, 2020
** runner
** File description:
** input init
*/

#include "runner.h"

input_t *input_init(void)
{
    input_t *input = malloc(sizeof(input));

    input->jump_key = DEFAULT_JUMP;
    input->jump_state = 0;
    return (input);
}
