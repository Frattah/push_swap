#include "push_swap.h"

void calc_moves_b(t_lst a, t_lst b)
{
    int mid;
    int i;
    t_elem * el;

    el = b->head;
    a->mov = (int *) malloc(sizeof(int) * b->ln);
    b->mov = (int *) malloc(sizeof(int) * b->ln);
    if (!a->mov || !b->mov)
        return ;
    mid = b->ln / 2;
    i = -1;
    while (++i < b->ln)
    {
        if (i <= mid)
            b->mov[i] = i;
        else
            b->mov[i] = i - b->ln;
        a->mov[i] = calc_moves_a(a, b->ln,el->num);
        el = el->next;
    }
    // for (int i = 0; i < b->ln; i++)
    //     printf("%d  %d\n", a->mov[i], b->mov[i]);
    choice_move(a,b);
}

int calc_moves_a(t_lst a, int size, int num)
{
    t_elem *el;
    int     i;
    int     mid;

    mid = a->ln / 2;
    i = -1;
    el = a->head;
    while (++i < a->ln)
    {
        if (el->num > num && el->prev->num < num)
            break;
        else if (is_min(a,el->num) && el->num > num)
            break;
        else if (is_max(a,el->prev->num) && el->prev->num < num)
            break;
        el = el->next;
    }
    if (i <= mid)
        return (i);
    return (i - a->ln);
}

void choice_move(t_lst a, t_lst b)
{
    int min;
    int i;
    int j;

    i = -1;
    min = INT_MAX;
    while (++i < b->ln)
    {
        if (((a->mov[i] >= 0 && b->mov[i] >= 0)
            || (a->mov[i] < 0 && b->mov[i] < 0))
            && (min > max(abs(a->mov[i]),abs(b->mov[i]))))
        {
            min = max(abs(a->mov[i]),abs(b->mov[i]));
            j = i;
        }
        else if (min > abs(a->mov[i]) + abs(b->mov[i]))
        {
            min = abs(a->mov[i]) + abs(b->mov[i]);
            j = i;
        }
    }
    // printf("min == %d,%d\n",min,j);
    push_swap(a, b, j);
    free(a->mov);
    free(b->mov);
}