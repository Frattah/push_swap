#include "push_swap.h"

void    rrot(t_lst l)
{
    l->head = l->tail;
    l->tail = l->prev[l->tail];
    printf("rra\n");
}

void    rot(t_lst l)
{
    l->tail = l->head;
    l->head = l->next[l->head];
    printf("ra\n");
}

void	push(t_lst a, t_lst b, int chunck)
{
	lst_ins_back(b, a->info[a->head].num);
	b->head = b->tail;
    b->tail = b->prev[b->tail];
    b->info[b->head].chunck = chunck;

	a->prev[a->next[a->head]] = a->tail;
    a->next[a->tail] = a->next[a->head];
	a->head = a->next[a->head];
    a->qnt--;
    printf("push\n");
}

void    swap(t_lst l)
{
    t_elem tmp;

    printf("sa\n");
    tmp = l->info[l->head];
    l->info[l->head] = l->info[l->next[l->head]];
    l->info[l->next[l->head]] = tmp; 
}
