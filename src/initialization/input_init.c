/*
** EPITECH PROJECT, 2020
** runner
** File description:
** input init
*/

#include "runner.h"

key_input_t *key_input_init(sfKeyCode key_code_value)
{
    key_input_t *key = malloc(sizeof(key_input_t));

    key->key_code = key_code_value;
    return (key);
}

input_t *input_init(void)
{
    input_t *input = malloc(sizeof(input_t));

    input->jump = key_input_init(DEFAULT_JUMP);
    input->quit = key_input_init(DEFAULT_QUIT);
    input->reset = key_input_init(DEFAULT_RESTART);
    return (input);
}
