#include "push_swap.h"

void    rrot(lst l)
{
    l->head = l->tail;
    l->tail = l->prev[l->tail];
    printf("rra\n");
}

void    rot(lst l)
{
    l->tail = l->head;
    l->head = l->next[l->head];
    printf("ra\n");
}

void	push(lst a, lst b)
{
	lst_ins_back(b, a->info[a->head]);
	rrot(b);

	a->prev[a->next[a->head]] = a->tail;
    a->next[a->tail] = a->next[a->head];
	a->head = a->next[a->head];
    a->qnt--;
    printf("push\n");
}

void    swap(lst l)
{
    int tmp;

    printf("sa\n");
    tmp = l->info[l->head];
    l->info[l->head] = l->info[l->next[l->head]];
    l->info[l->next[l->head]] = tmp; 
}
