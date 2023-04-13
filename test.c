#include "push_swap.h"

void	three_sort(t_lst a, t_lst b)
{
	if (a->head->num > a->head->next->num
			&& a->tail->num > a->head->next->num
			&& a->head->num < a->tail->num)
		swap(a);
	else if (a->head->num > a->head->next->num
			&& a->tail->num < a->head->next->num)
	{
		rot(a);
		swap(a);
	}
	else if (a->head->num < a->head->next->num
			&& a->tail->num < a->head->next->num
			&& a->head->num < a->tail->num)
	{
		rrot(a);
		swap(a);
	}
	else if (a->head->num > a->head->next->num
			&& a->tail->num > a->head->next->num
			&& a->head->num > a->tail->num)
		rot(a);
	else if (a->head->num < a->head->next->num
			&& a->tail->num < a->head->next->num
			&& a->head->num > a->tail->num)
		rrot(a);
}

int	main(int argc, char **argv)
{
	int	i;
	int	opt;
	t_lst	a;
	t_lst	b;
    
	i = 0;
	a = lst_init('a');
	b = lst_init('b');
	while (++i <= argc - 1)
		lst_ins_back(a, atoi(argv[i]));
	opt = midpoint(a);
	while (a->ln > 3)
	{
		push(a,b);
		if (b->head->num < opt && b->ln > 1)
			rot(b);
	}
	three_sort(a, b);
	while(a->ln != argc - 1)
		calc_moves_b(a, b);
	opt = rot_or_rrot(a);
	while(a->head->num > a->tail->num)
	{
		if (!opt)
			rot(a);
		else
			rrot(a);
	}
}
