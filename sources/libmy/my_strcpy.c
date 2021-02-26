/*
** ETNA PROJECT, 22/10/2020 by dousse_r
** /home/rdousset/Documents/PERSO/my_lib
** File description:
**      libmy
*/

#include "my.h"

char *my_strcpy(char *dest, char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}