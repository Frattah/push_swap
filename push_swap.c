#include "push_swap.h"

void push_swap(t_lst a, t_lst b, int j)
{
	int i;

	if ((a->mov[j] >= 0 && b->mov[j] >= 0)
			|| (a->mov[j] < 0 && b->mov[j] < 0))
	{
		i = 0;
        while (i < min(abs(a->mov[j]), abs(b->mov[j])))
        {
            if (a->mov[j] >= 0)
                double_rot(a,b);
            else
                double_rrot(a,b);
            i++;
        }
        while (i < max(abs(a->mov[j]), abs(b->mov[j])))
        {
            if (a->mov[j] > b->mov[j] && a->mov[j] >= 0)
                rot(a);
            else if (a->mov[j] >= 0)
                rot(b);
            if (a->mov[j] < b->mov[j] && a->mov[j] < 0)
                rrot(a);
            else if (a->mov[j] < 0)
                rrot(b);
            i++;
        }
    }
    i = -1;
    if (a->mov[j] >= 0 && b->mov[j] < 0)
    {
        while (++i < a->mov[j])
            rot(a);
        i = -1;
        while (++i < -b->mov[j])
            rrot(b);
    }
    if (a->mov[j] < 0 && b->mov[j] >= 0)
    {
        while (++i < -a->mov[j])
            rrot(a);
        i = -1;
        while (++i < b->mov[j])
            rot(b);
    }
    push(b,a);
}
