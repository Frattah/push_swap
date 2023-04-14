/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:39:25 by frmonfre          #+#    #+#             */
/*   Updated: 2023/04/13 08:39:50 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_or_rrot(t_lst l)
{
	t_elem	*el;
	int		i;

	i = -1;
	el = l->head;
	while (++i < l->ln && el->num < el->next->num)
		el = el->next;
	if (i < l->ln / 2)
		return (0);
	return (1);
}

void	sort(int *a, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	j = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

int	midpoint(t_lst l)
{
	t_elem	*el;
	int		i;
	int		*a;

	el = l->head;
	a = (int *) malloc(sizeof(int) * l->ln);
	if (!a)
		exit(1);
	i = -1;
	while (++i < l->ln)
	{
		a[i] = el->num;
		el = el->next;
	}
	sort(a, l->ln);
	i = a[l->ln / 2];
	free(a);
	return (i);
}
