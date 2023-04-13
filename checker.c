/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:41:39 by frmonfre          #+#    #+#             */
/*   Updated: 2023/04/13 08:45:02 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_lst a)
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
	int		i;
	int		j;
	int		tmp;
	int		ln;
	t_lst	a;
	t_lst	b;

	if (argc == 1)
		exit(1);
	i = 0;
	j = 0;
	tmp = 0;
	a = lst_init('a');
	b = lst_init('b');

	if (argc == 2)
	{
		while (argv[1][j])
		{
			tmp = ft_atoi(argv[1] + j);
			while (argv[1][j] && ((argv[1][j] >= '0' && argv[1][j] <= '9')
					|| (argv[1][j] == '-' && is_space(argv[1][j - 1]))))
				j++;
			while (argv[1][j] && is_space(argv[1][j]))
				j++;
			lst_ins_back(a, tmp);
		}
	}
	else
	{
		while (++i <= argc - 1)
		{
			tmp = ft_atoi(argv[i]);
			if (tmp == 0 && argv[i][0] - '0' != 0)
			{
				write(2,"Error\n",6);
				exit(1);
			}
			lst_ins_back(a, tmp);
		}
	}


	tmp = midpoint(a);
	if (duplicates(a))
	{
		write(2,"Error\n",6);
		exit(1);
	}
	ln = a->ln;
	while (a->ln > 3)
	{
		push(a, b);
		if (b->head->num < tmp && b->ln > 1)
			rot(b);
	}
	three_sort(a);

	while (a->ln != ln)
	{
		calc_moves_b(a, b);
	}

	tmp = rot_or_rrot(a);
		
	while (a->head->num > a->tail->num)
	{
		if (!tmp)
			rot(a);
		else
			rrot(a);
	}
	lst_del(a);
	lst_del(b);	
}
