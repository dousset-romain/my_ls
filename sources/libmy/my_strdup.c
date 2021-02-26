/*
** ETNA PROJECT, 22/10/2020 by dousse_r
** /home/rdousset/Documents/PERSO/my_lib
** File description:
**      libmy
*/

#include <stdlib.h>

#include "my.h"

char *my_strdup(char *src)
{
    char *dup;

    dup = malloc((my_strlen(src) + 1) * sizeof(dup));
    if (dup == NULL)
        return (NULL);
    return (my_strcpy(dup, src));
}