/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:41:03 by frmonfre          #+#    #+#             */
/*   Updated: 2023/04/13 11:21:54 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_moves_b(t_lst a, t_lst b)
{
	int		mid;
	int		i;
	t_elem	*el;

	el = b->head;
	a->mov = (int *) malloc(sizeof(int) * b->ln);
	b->mov = (int *) malloc(sizeof(int) * b->ln);
	if (!a->mov || !b->mov)
		return ;
	mid = b->ln / 2;
	i = -1;
	while (++i < b->ln)
	{
		if (i <= mid)
			b->mov[i] = i;
		else
			b->mov[i] = i - b->ln;
		a->mov[i] = calc_moves_a(a, el->num);
	el = el->next;
	}
	choice_move(a, b);
}

int	calc_moves_a(t_lst a, int num)
{
	t_elem	*el;
	int		i;
	int		mid;

	mid = a->ln / 2;
	i = -1;
	el = a->head;
	while (++i < a->ln)
	{
		if (el->num > num && el->prev->num < num)
			break ;
		else if (is_min(a, el->num) && el->num > num)
			break ;
		else if (is_max(a, el->prev->num) && el->prev->num < num)
			break ;
		el = el->next;
	}
	if (i <= mid)
		return (i);
	return (i - a->ln);
}

void	choice_move(t_lst a, t_lst b)
{
	int	min;
	int	i;
	int	j;

	i = -1;
	j = 0;
	min = INT_MAX;
	while (++i < b->ln)
	{
		if (((a->mov[i] >= 0 && b->mov[i] >= 0)
				|| (a->mov[i] < 0 && b->mov[i] < 0))
			&& (min > max(abs(a->mov[i]), abs(b->mov[i]))))
		{
			min = max(abs(a->mov[i]), abs(b->mov[i]));
			j = i;
		}
		else if (min > abs(a->mov[i]) + abs(b->mov[i]))
		{
			min = abs(a->mov[i]) + abs(b->mov[i]);
			j = i;
		}
	}
	push_swap1(a, b, j);
	free(a->mov);
	free(b->mov);
}
