/*
** ETNA PROJECT, 14/01/2021 by dousse_r
** /home/slowiizz/Documents/group-843271
** File description:
**      malloc and free header
*/

#ifndef _MALLOC_FREE_
#define _MALLOC_FREE_

char *copy_path(char *to_read, char *file_name);

void free_array(char **array);

char **array_allocation(int size, char *to_read);

char **store_params(int argc, char **argv, char mod);

int file_total(char *dir_to_read);

#endif /*_MALLOC_FREE_*/