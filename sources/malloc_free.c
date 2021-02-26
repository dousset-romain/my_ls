/*
** ETNA PROJECT, 14/01/2021 by dousse_r
** /home/slowiizz/Documents/group-843271
** File description:
**      allocation et libération de tableaux
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include "sorting.h"
#include "my.h"

char *copy_path(char *to_read, char *file_name)
{
    char *path;

    path = malloc((my_strlen(to_read) + my_strlen(file_name) + 2) * sizeof(char));
    path = my_strcpy(path, to_read);
    path = my_strcat(path, "/");
    path = my_strcat(path, file_name);
    return (path);
}

void free_array(char **array)
{
    int i;

    for (i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array[i]);
    free(array);
}

char **array_allocation(int size, char *to_read)
{
    char **file_array;
    DIR *dir;
    struct dirent *entry;
    int i;

    if ((dir = opendir(to_read)) == NULL)
        exit(1);
    file_array = malloc((size + 1) * sizeof(char *));
    if (file_array == NULL)
        exit(1);
    for (i = 0; (entry = readdir(dir)) != NULL; i++)
        file_array[i] = my_strdup(entry->d_name);
    file_array[i] = NULL;
    closedir(dir);
    return(file_array);
}

char **store_params(int argc, char **argv, char mod)
{
    char **array;
    int array_size = 0;
    int i = 0;

    for (int count = 1; count < argc; count++)
        if (argv[count][0] == '-' && mod == 'c')
            array_size++;
        else
            if (argv[count][0] != '-' && mod == 'd')
                array_size++;
    array = malloc((array_size + 1) * sizeof(char *));
    if (array == NULL)
        exit(1);
    for (int count = 1; count < argc; count++) {
        if (argv[count][0] == '-' && mod == 'c') {
            array[i] = my_strdup(argv[count]);
            i++;
        } else
            if (argv[count][0] != '-' && mod == 'd') {
                array[i] = my_strdup(argv[count]);
                i++;
            }
    };
    array[i] = NULL;
    return (array);
}

int file_total(char *dir_to_read)
{
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    dir = opendir(dir_to_read);
    if (dir == NULL) {
        my_putstr("my_ls: cannot access '");
        my_putstr(dir_to_read);
        my_putstr("'\n");
        return(-1);
    }
    while ((entry = readdir(dir)) != NULL)
        count++;
    closedir(dir);
    return(count);
}