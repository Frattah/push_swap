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

#include "checker.h"

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

void	build_lst_from_args(t_lst a, int argc, char **argv)
{
	int	i;
	int	tmp;

	i = 0;
	while (++i <= argc - 1)
	{
		tmp = ft_atoi(argv[i]);
		if (tmp == 0 && argv[i][0] - '0' != 0)
		{
			tmp = write(2, "Error\n", 6);
			exit(1);
		}
		lst_ins_back(a, tmp);
	}
}

void	build_lst_from_str(t_lst a, char **argv)
{
	int	j;
	int	tmp;

	j = 0;
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

void	is_sorted(t_lst l)
{
	int		tmp;
	int		i;
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
	if (tmp < 2)
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	int		ln;
	t_lst	a;
	t_lst	b;

	if (argc == 1)
		exit(1);
	if (non_integer(argc, argv))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	a = lst_init('a');
	b = lst_init('b');
	if (argc == 2)
		build_lst_from_str(a, argv);
	else
		build_lst_from_args(a, argc, argv);
	if (duplicates(a))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	ln = a->ln;
	push_swap0(a, b, ln);
	lst_del(a);
	lst_del(b);
}
