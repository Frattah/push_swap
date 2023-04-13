/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:36:40 by frmonfre          #+#    #+#             */
/*   Updated: 2023/04/13 08:36:45 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrot(t_lst l)
{
	l->head = l->tail;
	l->tail = l->tail->prev;
	if (l->id == 'a')
		printf("rra\n");
	else if (l->id == 'b')
		printf("rrb\n");
}

void	rot(t_lst l)
{
	l->tail = l->head;
	l->head = l->head->next;
	if (l->id == 'a')
		printf("ra\n");
	else if (l->id == 'b')
		printf("rb\n");
}

void	double_rrot(t_lst a, t_lst b)
{
	a->head = a->tail;
	a->tail = a->tail->prev;
	b->head = b->tail;
	b->tail = b->tail->prev;
	printf("rrr\n");
}

void	double_rot(t_lst a, t_lst b)
{
	a->tail = a->head;
	a->head = a->head->next;
	b->tail = b->head;
	b->head = b->head->next;
	printf("rr\n");
}
