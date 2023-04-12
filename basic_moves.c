#include "push_swap.h"

void    rrot(t_lst l)
{
    l->head = l->tail;
    l->tail = l->tail->prev;
    l->cnt++;
    if (l->id == 'a')
        printf("rra\n");
    else if (l->id == 'b')
        printf("rrb\n");
}

void    rot(t_lst l)
{
    l->tail = l->head;
    l->head = l->head->next;
    l->cnt++;
    if (l->id == 'a')
        printf("ra\n");
    else if (l->id == 'b')
        printf("rb\n");
}

void    double_rrot(t_lst a, t_lst b)
{
    a->head = a->tail;
    a->tail = a->tail->prev;
    b->head = b->tail;
    b->tail = b->tail->prev;
    a->cnt++;
    printf("rrr\n");
}

void    double_rot(t_lst a, t_lst b)
{
    a->tail = a->head;
    a->head = a->head->next;    
    b->tail = b->head;
    b->head = b->head->next;
    a->cnt++;
    printf("rr\n");
}

void	push(t_lst a, t_lst b)
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
    a->cnt++;
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
