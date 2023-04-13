#include "push_swap.h"

int	abs(int x)
{
	if (x > 0)
		return (x);
	return (-x);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	is_min(t_lst a, int min)
{
	int	i;
	t_elem	*el;

	i = -1;
	el = a->head;
	while (++i < a->ln)
	{
		if (min > el->num)
			return (0);
		el = el->next;
	}
	return (1);
}

int	is_max(t_lst a, int max)
{
	int	i;
	t_elem	*el;

	i = -1;
	el = a->head;
	while (++i < a->ln)
	{
		if (max < el->num)
			return (0);
		el = el->next;
	}
	return (1);
}
