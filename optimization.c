#include "push_swap.h"

int rot_or_rrot(t_lst l)
{
    t_elem *el;
    int i;

    i = -1;
    el = l->head;
    while (++i < l->ln && el->num < el->next->num)
        el = el->next;
    if (i < l->ln / 2)
        return (0);
    return (1);
}