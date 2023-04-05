#include "push_swap.h"

int find_midpoint(t_lst l, int col)
{
    int a[l->ln];
    t_elem  *i;
    int tmp;
    int j;
    int k;

    j = -1;
    i  = l->head;
    while (++j < l->ln && i->col == col)        
    {
        i = i->next;
        a[j] = i->num;
    }
    j = -1;
	while (++j < l->ln)
	{
		k = -1;
		while (++k < l->ln - 1)
		{
			if (a[k] > a[k + 1])
			{
				tmp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = tmp;
			}
		}
	}
    return (a[l->ln / 2]);
}