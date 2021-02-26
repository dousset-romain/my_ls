/*
** ETNA PROJECT, 14/01/2021 by dousse_r
** /home/slowiizz/Documents/group-843271
** File description:
**      gerer les commandes de l'utilisateur
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "my_print.h"
#include "malloc_free.h"
#include "sorting.h"
#include "my_modes.h"
#include "my.h"

int check_sort_command(char **commands)
{
    int count = 0;

    for (int i = 0; commands[i] != NULL && count < 2; i++)
        if (my_strcmp(commands[i], "-r") == 0) {
            count++;
            break;
        }
    for (int i = 0; commands[i] != NULL && count < 2; i++)
        if (my_strcmp(commands[i], "-t") == 0) {
            count += 2;
            break;
        }
    return (count);
}

char **sort_selection(char **commands, char *to_read)
{
    int array_size;
    char **file_array;

    if ((array_size = file_total(to_read)) == -1)
        exit(1);
    file_array = array_allocation(array_size, to_read);
    switch (check_sort_command(commands)) {
    case 0:
        file_array = my_sort_params(array_size, file_array);
        break;
    case 1:
        file_array = my_sort_params_reverse(array_size, file_array);
        break;
    case 2:
        file_array = my_sort_time(array_size, file_array, to_read);
        break;
    case 3:
        file_array = my_sort_time_reverse(array_size, file_array, to_read);
        break;
    }
    return (file_array);
}

int hidden_files(char **commands)
{
    int mode = 0;

    for (int i = 0; commands[i] != NULL; i++) {
        if (my_strcmp(commands[i], "-a") == 0)
            mode = 1;
        if (my_strcmp(commands[i], "-A") == 0)
            mode = 2;
    }
    return (mode);
}

int info_mode(char **commands)
{
    for (int i = 0; commands[i] != NULL; i++)
        if (my_strcmp(commands[i], "-l") == 0)
            return (1);
    return (0);
}

int d_mode(char **commands)
{
    for (int i = 0; commands[i] != NULL; i++)
        if (my_strcmp(commands[i], "-d") == 0)
            return (1);
    return (0);
}

int L_mode(char **commands)
{
    for (int i = 0; commands[i] != NULL; i++)
        if (my_strcmp(commands[i], "-L") == 0)
            return (1);
    return (0);
}

int recursion_mode(char **commands)
{
    for (int i = 0; commands[i] != NULL; i++)
        if (my_strcmp(commands[i], "-R") == 0)
            return (1);
    return (0);
}

void display_selection(char **commands, char **file_array, char *to_read)
{
    int hidden;
    int info;
    int directory;
    int link;
    struct stat stats;

    link = L_mode(commands);
    directory = d_mode(commands);
    hidden = hidden_files(commands);
    info = info_mode(commands);
    if (directory) {
        if (info && lstat(to_read, &stats) == 0)
            printstats(stats, to_read);
        else
            my_putstr(to_read);
        my_putchar('\n');
    } else
        if (recursion_mode(commands))
            recursion(commands, file_array, to_read, info, hidden, link);
        else
            normal(file_array, to_read, info, hidden, link);
}

void command(char **commands, char *to_read)
{
    char **array;
    
    array = sort_selection(commands, to_read);
    display_selection(commands, array, to_read);
    free_array(array);
}