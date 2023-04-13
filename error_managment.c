/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:19:22 by frmonfre          #+#    #+#             */
/*   Updated: 2023/04/13 11:21:12 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
