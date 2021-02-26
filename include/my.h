/*
** ETNA PROJECT, 22/10/2020 by dousse_r
** /home/rdousset/Documents/PERSO/my_lib
** File description:
**      my header
*/

#ifndef _MY_H_
#define _MY_H_

void my_putchar(char c);

void my_putstr(char *str);

int my_strlen(char *str);

int my_getnbr(char *str);

void my_putnbr(int nb);

void my_isneg(int nb);

void my_swap(int *a, int *b);

char *my_strcpy(char *dest, char *src);

char *my_strncpy(char *dest, char *src, int n);

int my_strcmp(char *s1, char *s2);

int my_strncmp(char *s1, char *s2, int n);

char *my_strcat(char *dest, char *src);

char *my_strncat(char *dest, char *src, int nb);

char *my_strstr(char *str, char *to_find);

char *my_strdup(char *src);

#endif /*_MY_H_*/