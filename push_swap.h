#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_elem
{
    int num;
    int chunck;
    struct s_elem *next;
    struct s_elem *prev;
} t_elem;

struct s_lst
{
    t_elem *head;
    t_elem *tail;
    int curr_chunck;
    int qnt;
};

typedef struct s_lst *t_lst;

t_lst     lst_new(int size);

void    lst_print(t_lst l);

void    lst_ins_back(t_lst l, int v);

void    lst_debug(t_lst l);

int     lst_is_ordered(t_lst l);

int find_midpoint(t_lst l);

void    rot(t_lst l);

void    rrot(t_lst l);

void    swap(t_lst l);

void    push(t_lst a, t_lst b, int chunck);

void	push_swap(t_lst a, t_lst b);

void    start(t_lst a, t_lst b);

int chunck_ordered(t_lst l, int chunck);

int pushable(t_lst l, int mid);

int rot_or_rrot(t_lst l, int mid);

// int     lis(lst a);

#endif
