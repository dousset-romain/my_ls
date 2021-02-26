/*
** ETNA PROJECT, 14/01/2021 by dousse_r
** /home/slowiizz/Documents/group-843271
** File description:
**      sorting header
*/

#ifndef _SORTING_
#define _SORTING_

int my_timecmp(struct stat file1, struct stat file2);

char **my_sort_params(int nb_param, char **tab_param);

char **my_sort_params_reverse(int nb_param, char **tab_param);

char **my_sort_time(int nb_param, char **tab_param, char *dir);

char **my_sort_time_reverse(int nb_param, char **tab_param, char *dir);

#endif /*_SORTING_*/