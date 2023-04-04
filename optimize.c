#include "push_swap.h"

int pushable(t_lst l, int mid)
{
    int	j = 0;
    int i = l->head;

    while (j < l->qnt)        
    {
        i = l->next[i];
        if (l->info[i].num < mid)
            return (1);
	    j++;
    }
    return (0);
}

int rot_or_rrot(t_lst l, int mid)
{
    int i;
    int j;
    int weight1;
    int weight2;

    weight1 = 0;
    weight2 = 0;
    i = l->qnt / 2;
    j = l->qnt / 2;
    while (i > 0)
    {
        if (mid > l->info[j].num)
            weight1 += l->qnt / 2 - 1 - i;
        j = l->prev[j];
        i--;
    }
    i = l->qnt / 2;
    j = l->qnt / 2;
    while (i < l->qnt)
    {
        if (mid > l->info[j].num)
            weight2 += i - l->qnt / 2;
        j = l->next[j];
        i++;
    }
    if (weight1 > weight2)
        return (1);
    return (0);
}