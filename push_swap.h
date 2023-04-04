#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct LST_STRUCT
{
    int *next;
    int *info;
    int *prev;
    int tail;
    int head;
    int free;
    int size;
    int qnt;
}   lst_struct;

typedef lst_struct *lst;

lst     lst_new(int size);

void    lst_print(lst l);

void    lst_debug(lst l);

void    lst_ins_back(lst l, int v);

int     lst_is_ordered(lst l);

void    rot(lst l);

void    rrot(lst l);

void    swap(lst l);

void    push(lst a, lst b);

int     lis(lst a);

#endif
