#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_elem
{
    int num;
    int col;
    struct s_elem *next;
    struct s_elem *prev;
} t_elem;

struct s_lst
{
    t_elem *head;
    t_elem *tail;
    int cur_col;
    int ln;
    char id;
};

typedef struct s_lst *t_lst;

t_lst     lst_init(char id);

void    lst_print(t_lst l);

void    lst_ins_back(t_lst l, int v);

int     lst_is_ordered(t_lst l, int col);

int find_midpoint(t_lst l, int col);

void    rot(t_lst l);

void    rrot(t_lst l);

void    swap(t_lst l);

void    push(t_lst a, t_lst b, int chunck);

void	push_swap(t_lst a, t_lst b);

void    start(t_lst a, t_lst b);

int pushable(t_lst l, int mid);

int rot_or_rrot(t_lst l, int mid);

#endif
