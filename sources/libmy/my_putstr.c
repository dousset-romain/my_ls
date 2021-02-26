/*
** ETNA PROJECT, 22/10/2020 by dousse_r
** /home/rdousset/Documents/PERSO/my_lib
** File description:
**      libmy
*/

#include "my.h"

void my_putstr(char *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
}