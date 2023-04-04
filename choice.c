#include "push_swap.h"

int find_midpoint(t_lst l)
{
    int a[l->qnt];
    int	j;
    int i;
    int tmp;

    j = -1;
    i  = l->head;
    while (++j < l->qnt)        
    {
        i = l->next[i];
        a[j] = l->info[i].num;
    }
    j = -1;
	while (++j < l->qnt)
	{
		i = -1;
		while (++i < l->qnt - 1)
		{
			if (a[i] > a[i + 1])
			{
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		}
	}
    return (a[l->qnt / 2]);
}