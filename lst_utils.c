/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:40:33 by frmonfre          #+#    #+#             */
/*   Updated: 2023/04/14 11:40:29 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	duplicates(t_lst a)
{
	int		i;
	int		j;
	t_elem	*el1;
	t_elem	*el2;

	i = -1;
	el1 = a->head;
	while (++i < a->ln)
	{
		j = i;
		el2 = el1->next;
		while (++j < a->ln)
		{
			if (el2->num == el1->num)
				return (1);
			el2 = el2->next;
		}
		el1 = el1->next;
	}
	return (0);
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
		l->head->prev = nw;
	}
	nw->num = v;
	l->tail = nw;
	if (l->ln == 0)
		l->head = nw;
	l->ln++;
}

void	lst_del(t_lst l)
{
	int		i;
	t_elem	*el;

	if (l->ln == 0)
	{
		free(l);
		return ;
	}
	i = 0;
	el = l->tail;
	while (i < l->ln - 1)
	{
		el = el->prev;
		free(el->next);
		i++;
	}
	free(l->head);
	free(l);
}

int	is_sorted(t_lst l)
{
	int		tmp;
	int		i;
	t_elem	*el;

	el = l->head;
	i = 0;
	tmp = 0;
	while (++i < l->ln)
	{
		if (el->num > el->next->num)
			tmp++;
		el = el->next;
	}
	return (tmp < 2);
}
