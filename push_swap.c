/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:47:02 by frmonfre          #+#    #+#             */
/*   Updated: 2023/04/13 11:18:55 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap0(t_lst a, t_lst b)
{
	int	ln;
	int	tmp;

	ln = a->ln;
	if (is_sorted(a))
		exit(0);
	tmp = midpoint(a);
	while (a->ln > 3)
	{
		push(a, b);
		if (b->head->num < tmp && b->ln > 1)
			rot(b);
	}
	three_sort(a);
	while (a->ln != ln)
		calc_moves_b(a, b);
	tmp = rot_or_rrot(a);
	while (a->head->num > a->tail->num)
	{
		if (!tmp)
			rot(a);
		else
			rrot(a);
	}
}

void	push_swap1(t_lst a, t_lst b, int j)
{
	int	i;

	i = -1;
	if (a->mov[j] >= 0 && b->mov[j] < 0)
	{
		while (++i < a->mov[j])
			rot(a);
		i = -1;
		while (++i < -b->mov[j])
			rrot(b);
		return ;
	}
	if (a->mov[j] < 0 && b->mov[j] >= 0)
	{
		while (++i < -a->mov[j])
			rrot(a);
		i = -1;
		while (++i < b->mov[j])
			rot(b);
		return ;
	}
	push_swap2(a, b, j);
}

void	push_swap2(t_lst a, t_lst b, int j)
{
	int	i;

	i = 0;
	while (i < min(abs(a->mov[j]), abs(b->mov[j])))
	{
		if (a->mov[j] >= 0)
			double_rot(a, b);
		else
			double_rrot(a, b);
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
	push(b, a);
}
