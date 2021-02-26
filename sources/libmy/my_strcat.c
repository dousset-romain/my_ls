/*
** ETNA PROJECT, 22/10/2020 by dousse_r
** /home/rdousset/Documents/PERSO/my_lib
** File description:
**      libmy
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;

    for (i = 0; dest[i] != 0; ++i);
    return (my_strcpy(dest + i, src) - i);
}