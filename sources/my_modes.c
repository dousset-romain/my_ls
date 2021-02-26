/*
** ETNA PROJECT, 15/01/2021 by dousse_r
** /home/slowiizz/Documents/group-843271
** File description:
**      modes choisis par command
*/

#include <sys/stat.h>
#include <stdlib.h>
#include "command.h"
#include "malloc_free.h"
#include "my.h"
#include "my_print.h"

int is_directory(struct stat stats)
{
    if (S_ISDIR(stats.st_mode))
        return (1);
    else
        return (0);
}

void my_stat(char **file_array, char *to_read, int hidden, int link)
{
    char *path;
    struct stat stats;

    for (int i = 0; file_array[i] != NULL; i++) {
        path = copy_path(to_read, file_array[i]);
        if (link) {
            if (stat(path, &stats) != 0)
                exit(1);
        } else
            if (lstat(path, &stats) != 0)
                exit(1);
        if (hidden == 0)
            if (file_array[i][0] != '.') {
                printstats(stats, file_array[i]);
                my_putchar('\n');
            }
        if (hidden == 1) {
            printstats(stats, file_array[i]);
            my_putchar('\n');
        }
        if (hidden == 2)
            if ((my_strcmp(file_array[i], ".") && my_strcmp(file_array[i], ".."))) {
                printstats(stats, file_array[i]);
                my_putchar('\n');
            }
        free(path);
    }
}

void recursion_hidden(char **commands, char **file_array, char *to_read, int info, int hidden, int link)
{
    struct stat stats;
    char *path;

    my_putchar('\n');
    my_putstr(to_read);
    my_putstr(":\n");
    if (info == 1)
        my_stat(file_array, to_read, hidden, link);
    else
        print_array(file_array, hidden);
    for (int i = 0; file_array[i] != NULL; i++) {
        if ((my_strcmp(file_array[i], ".") && my_strcmp(file_array[i], ".."))) {
            path = copy_path(to_read, file_array[i]);
            if (lstat(path, &stats) == 0)
                if (is_directory(stats))
                    command(commands, path);
            free(path);
        }
    }
}

void recursion_normal(char **commands, char **file_array, char *to_read, int info, int hidden, int link)
{
    struct stat stats;
    char *path;

    my_putchar('\n');
    my_putstr(to_read);
    my_putstr(":\n");
    if (info == 1)
        my_stat(file_array, to_read, hidden, link);
    else
        print_array(file_array, hidden);
    for (int i = 0; file_array[i] != NULL; i++) {
        if (file_array[i][0] != '.') {
            path = copy_path(to_read, file_array[i]);
            if (lstat(path, &stats) == 0)
                if (is_directory(stats))
                    command(commands, path);
            free(path);
        }
    }
}

void recursion(char **commands, char **file_array, char *to_read, int info, int hidden, int link)
{
    if (hidden == 0)
        recursion_normal(commands, file_array, to_read, info, hidden, link);
    else
        recursion_hidden(commands, file_array, to_read, info, hidden, link);
}

void normal(char **file_array, char *to_read, int info, int hidden, int link)
{
    my_putchar('\n');
    my_putstr(to_read);
    my_putstr(":\n");
    if (info == 1)
        my_stat(file_array, to_read, hidden, link);
    else
        print_array(file_array, hidden);
}