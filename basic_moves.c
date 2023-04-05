#include "push_swap.h"

void    rrot(t_lst l)
{
    l->head = l->tail;
    l->tail = l->tail->prev;
    if (l->id == 'a')
        printf("rra\n");
    else if (l->id == 'b')
        printf("rrb\n");
}

void    rot(t_lst l)
{
    l->tail = l->head;
    l->head = l->head->next;
        if (l->id == 'a')
        printf("ra\n");
    else if (l->id == 'b')
        printf("rb\n");
}

void	push(t_lst a, t_lst b, int col)
{
    t_elem *pu;

    pu = a->head;
    if (a->id == 'a')
        printf("pa\n");
    else if (a->id == 'b')
        printf("pb\n");
    a->head = a->head->next;
    a->head->prev = a->tail;
    a->tail->next = a->head;
    if (b->head != NULL && b->tail != NULL)
    {
        b->head->prev = pu; 
        b->tail->next = pu;
        pu->next = b->head;
        pu->prev = b->tail; 
        b->head = pu;
    }
    else if (b->head == NULL && b->tail == NULL)
    {
        b->head = pu;
        b->tail = pu;
        pu->next = pu;
        pu->prev = pu;
    }
    a->ln--;
    b->ln++;
}

void    swap(t_lst l)
{
    int tmp;

    if (l->id == 'a')
        printf("sa\n");
    else
        printf("sb\n");
    tmp =  l->head->num;
    l->head->num = l->head->next->num;
    l->head->next->num = tmp;
}
