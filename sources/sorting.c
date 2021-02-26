/*
** ETNA PROJECT, 14/01/2021 by dousse_r
** /home/slowiizz/Documents/group-843271
** File description:
**      Les différents types de tri de my_ls
*/

#include <sys/stat.h>
#include <stdlib.h>
#include "malloc_free.h"
#include "my_print.h"
#include "my.h"

char **my_strswap(char **tab_param, int i, int j)
{
    char *temp;

    temp = tab_param[i];
    tab_param[i] = tab_param[j];
    tab_param[j] = temp;
    return (tab_param);
}

char **my_reverse_array(char **array, int start, int end)
{
    while (start <= end) {
        array = my_strswap(array, start, end);
        start++;
        end--;
    }
    return (array);
}

int my_timecmp(struct stat file1, struct stat file2)
{
    if (file1.st_mtime <= file2.st_mtime)
        return(1);
    else
        return (0);
}

char **my_sort_params(int nb_param, char **tab_param)
{
    int i = 0;
    int swap;

    while (i < nb_param - 1) {
        swap = my_strcmp(tab_param[i], tab_param[i + 1]);
        if (swap > 0) {
            tab_param = my_strswap(tab_param, i, i + 1);
            i = 0;
        } else
            ++i;
    }
    return (tab_param);
}

char **my_sort_params_reverse(int nb_param, char **tab_param)
{
    tab_param = my_sort_params(nb_param, tab_param);
    tab_param = my_reverse_array(tab_param, 0, nb_param - 1);
    return (tab_param);
}


char **my_sort_time_reverse(int nb_param, char **tab_param, char *dir)
{
    int i = 0;
    struct stat file1;
    struct stat file2;
    char *path;

    while (i < nb_param - 1) {
        path = copy_path(dir, tab_param[i]);
        if (lstat(path, &file1) != 0)
            exit(1);
        free(path);
        path = copy_path(dir, tab_param[i + 1]);
        if (lstat(path, &file2) != 0)
            exit(1);
        free(path);
        if (my_timecmp(file1, file2) == 0) {
            tab_param = my_strswap(tab_param, i, i + 1);
            i = 0;
        } else
            ++i;
    }
    return (tab_param);
}
char **my_sort_time(int nb_param, char **tab_param, char *dir)
{
    tab_param = my_sort_time_reverse(nb_param, tab_param, dir);
    tab_param = my_reverse_array(tab_param, 0, nb_param - 1);
    return (tab_param);
}