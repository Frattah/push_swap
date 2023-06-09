/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:39:05 by frmonfre          #+#    #+#             */
/*   Updated: 2023/04/13 08:39:07 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_lst a, t_lst b)
{
	t_elem	*pu;

	pu = a->head;
	a->ln--;
	b->ln++;
	if (a->id == 'a')
		write(1, "pb\n", 3);
	else if (a->id == 'b')
		write(1, "pa\n", 3);
	a->head = a->head->next;
	a->head->prev = a->tail;
	a->tail->next = a->head;
	if (b->head != NULL && b->tail != NULL)
	{
		b->head->prev = pu;
		b->tail->next = pu;
		pu->next = b->head;
		pu->prev = b->tail;
		b->head = pu;
		return ;
	}
	b->head = pu;
	b->tail = pu;
	pu->next = pu;
	pu->prev = pu;
}

void	swap(t_lst l)
{
	int	tmp;

	if (l->id == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	tmp = l->head->num;
	l->head->num = l->head->next->num;
	l->head->next->num = tmp;
}
