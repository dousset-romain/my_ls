/*
** ETNA PROJECT, 22/10/2020 by dousse_r
** /home/rdousset/Documents/PERSO/my_lib
** File description:
**      libmy
*/

#include "my.h"

int my_strlen(char *str)
{
    int i;
    
    for (i = 0; str[i]; i++);
    return (i);
}