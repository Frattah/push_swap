#include "push_swap.h"

void	lst_print(t_lst l)
{
	int	j;
	t_elem	*i;

	j = 0;
	printf("\n");
	if (l->id == 'a')
		printf("A:  ");
	else if (l->id == 'b')
		printf("B:  ");
	i = l->head;
	while (j < l->ln)
	{
		printf("(%d)", i->num);
		if (j + 1 != l->ln)
			printf("->");
		i = i->next;
		j++;
	}
	printf("\n");
}

t_lst	lst_init(char id)
{
	t_lst	l;

	l = (t_lst) malloc(sizeof(struct s_lst));
	if (!l)
		return (NULL);
	l->head = NULL;
	l->tail = NULL;
	l->ln = 0;
	l->id = id;
	return (l);
}

void	lst_ins_back(t_lst l, int v)
{
	t_elem	*nw;

	nw = (t_elem *) malloc(sizeof(t_elem));
	if (!nw)
		return ;
	if (l->tail == NULL)
	{
		nw->prev = nw;
		nw->next = nw;
	}
	else
	{
		nw->prev = l->tail;
		nw->next = l->head;
		l->tail->next = nw;
	}
	nw->num = v;
	l->tail = nw;
	if (l->ln == 0)
		l->head = nw;
	l->ln++;
}

int	is_sorted(t_lst l)
{
	int	tmp;
	int	i;
	t_elem	*el;

	el = l->head;
	i = -1;
	tmp = 0;
	while (++i < l->ln)
	{
		if (el->num > el->next->num)
			tmp++;
		el = el->next;
	}
	return (tmp < 2);
}
