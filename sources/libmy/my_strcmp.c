/*
** ETNA PROJECT, 22/10/2020 by dousse_r
** /home/rdousset/Documents/PERSO/my_lib
** File description:
**      libmy
*/

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != 0) {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
        ++i;
    }
    if (s1[i] < s2[i])
        return (-1);
    return (0);
}