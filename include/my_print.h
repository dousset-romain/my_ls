/*
** ETNA PROJECT, 14/01/2021 by dousse_r
** /home/slowiizz/Documents/group-843271
** File description:
**      my print header
*/

#ifndef _MY_PRINT_
#define _MY_PRINT_

void printstats(struct stat stats, char *file_name);

void usr_rights(struct stat stats);

void grp_rights(struct stat stats);

void oth_rights(struct stat stats);

void file_type(struct stat stats);

void rights(struct stat stats);

void names(struct stat stats);

void print_array(char **array, int hidden);

#endif /*_MY_PRINT_*/