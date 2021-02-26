/*
** ETNA PROJECT, 14/01/2021 by dousse_r
** /home/slowiizz/Documents/group-843271
** File description:
**      afficher les données
*/

#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "my.h"

void print_array(char **array, int hidden)
{
    for (int i = 0; array[i] != NULL; i++) {
        if (hidden == 0)
            if (array[i][0] != '.') {
                my_putstr(array[i]);
                my_putchar('\n');
            }
        if (hidden == 1) {
            my_putstr(array[i]);
            my_putchar('\n');
        }
        if (hidden == 2)
            if ((my_strcmp(array[i], ".") && my_strcmp(array[i], ".."))) {
                my_putstr(array[i]);
                my_putchar('\n');
            }
    };
}


void usr_rights(struct stat stats)
{
    if (stats.st_mode & S_IRUSR)
        my_putchar('r');
    else
        my_putchar('-');
    if (stats.st_mode & S_IWUSR)
        my_putchar('w');
    else
        my_putchar('-');
    if (stats.st_mode & S_IXUSR)
        my_putchar('x');
    else
        my_putchar('-');
}

void grp_rights(struct stat stats)
{
    if (stats.st_mode & S_IRGRP)
        my_putchar('r');
    else
        my_putchar('-');
    if (stats.st_mode & S_IWGRP)
        my_putchar('w');
    else
        my_putchar('-');
    if (stats.st_mode & S_IXGRP)
        my_putchar('x');
    else
        my_putchar('-');
}

void oth_rights(struct stat stats)
{
    if (stats.st_mode & S_IROTH)
        my_putchar('r');
    else
        my_putchar('-');
    if (stats.st_mode & S_IWOTH)
        my_putchar('w');
    else
        my_putchar('-');
    if (stats.st_mode & S_IXOTH)
        my_putchar('x');
    else
        my_putchar('-');
}

void file_type(struct stat stats)
{
    if (S_ISDIR(stats.st_mode))
        my_putchar('d');
    else
        if (S_ISCHR(stats.st_mode))
            my_putchar('c');
        else
            if (S_ISLNK(stats.st_mode))
                my_putchar('l');
            else
                if (S_ISBLK(stats.st_mode))
                    my_putchar('b');
                else
                    my_putchar('-');
}

void rights(struct stat stats)
{
    file_type(stats);
    usr_rights(stats);
    grp_rights(stats);
    oth_rights(stats);
    my_putchar('\t');
}

void names(struct stat stats)
{
    struct passwd *pw;
    struct group *gr;

    pw = getpwuid(stats.st_uid);
    gr = getgrgid(stats.st_gid);
    my_putchar('\t');
    my_putstr(pw->pw_name);
    my_putchar('\t');
    my_putchar('\t');
    my_putstr(gr->gr_name);
    my_putchar('\t');
    my_putchar('\t');
}

void printstats(struct stat stats, char *file_name)
{
    char times[80];

    rights(stats);
    my_putnbr(stats.st_nlink);
    names(stats);
    my_putnbr(stats.st_size);
    my_putchar('\t');
    strftime(times, 80, "%b %d %H:%M\t", localtime(&stats.st_mtime));
    my_putstr(times);
    my_putstr(file_name);
}