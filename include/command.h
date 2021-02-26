/*
** ETNA PROJECT, 14/01/2021 by dousse_r
** /home/slowiizz/Documents/group-843271
** File description:
**      command header
*/

#ifndef _COMMAND_H_
#define _COMMAND_H_

int check_sort_command(char **commands);

char **sort_selection(char **commands, char *to_read);

void command(char **commands, char *to_read);

#endif /*_COMMAND_H_*/