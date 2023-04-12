#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_elem
{
    int num;
    struct s_elem *next;
    struct s_elem *prev;
} t_elem;

struct s_lst
{
    t_elem *head;
    t_elem *tail;
    int *mov;
    int ln;
    int cnt;
    char id;
};

typedef struct s_lst *t_lst;

t_lst     lst_init(char id);

void    lst_print(t_lst l);

void    lst_ins_back(t_lst l, int v);

int     lis(t_lst l);

void    rot(t_lst l);

void    double_rot(t_lst a, t_lst b);

void    rrot(t_lst l);

void    double_rrot(t_lst a, t_lst b);

void    swap(t_lst l);

void    push(t_lst a, t_lst b);



void     calc_moves_b(t_lst a, t_lst b);

int     calc_moves_a(t_lst a, int size, int num);

void     choice_move(t_lst a, t_lst b);

int     abs(int x);

int     max(int a, int b);

int     min(int a, int b);

int     is_min(t_lst a, int min);

int     is_max(t_lst a, int max);

void    push_swap(t_lst a, t_lst b, int index);

int     is_sorted(t_lst a);

int     rot_or_rrot(t_lst l);

int     midpoint(t_lst l);

#endif
