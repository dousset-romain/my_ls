/*
** ETNA PROJECT, 15/01/2021 by dousse_r
** /home/slowiizz/Documents/group-843271
** File description:
**      my putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}