/*
** ETNA PROJECT, 11/01/2021 by dousse_r
** /home/slowiizz/Documents/group-843271
** File description:
**      Read directories
*/

#include <stdlib.h>
#include "command.h"
#include "malloc_free.h"
#include "my.h"

int main(int argc, char **argv)
{
    char **directory_array;
    char **command_array;

    directory_array = store_params(argc, argv, 'd');
    command_array = store_params(argc, argv, 'c');
    if (directory_array[0] == NULL)
        command(command_array, ".");
    else
        for (int i = 0; directory_array[i] != NULL; i++)
            command(command_array, directory_array[i]);
    free_array(command_array);
    free_array(directory_array);
    return (0);
}