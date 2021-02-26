/*
** ETNA PROJECT, 22/10/2020 by dousse_r
** /home/rdousset/Documents/PERSO/my_lib
** File description:
**      libmy
*/

#include "my.h"

void my_putnbr(int nb)
{
    int i = 1000000000;
    
    if (nb == 0)
        my_putchar('0');
    else
        if (nb == -2147483648)
            my_putstr("-2147483648");
        else {
            if (nb < 0) {
                my_putchar('-');
                nb = -nb;
            }
            for (i = i; (nb / i) <= 0; i /= 10);
            for (i = i; i >= 1; i /= 10) {
                my_putchar(nb / i + '0');
                nb %= i;
            }
        }
}