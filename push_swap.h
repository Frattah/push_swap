/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:45:12 by frmonfre          #+#    #+#             */
/*   Updated: 2023/04/14 09:42:56 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_elem
{
	int				num;
	struct s_elem	*next;
	struct s_elem	*prev;
}	t_elem;

struct s_lst
{
	t_elem	*head;
	t_elem	*tail;
	int		*mov;
	int		ln;
	char	id;
};

typedef struct s_lst	*t_lst;

void	rrot(t_lst l);

void	rot(t_lst l);

void	double_rrot(t_lst a, t_lst b);

void	double_rot(t_lst a, t_lst b);

void	push(t_lst a, t_lst b);

void	swap(t_lst l);

void	calc_moves_b(t_lst a, t_lst b);

int		calc_moves_a(t_lst a, int num);

void	choice_move(t_lst a, t_lst b);

t_lst	lst_init(char id);

int		duplicates(t_lst a);

void	lst_ins_back(t_lst l, int v);

void	lst_del(t_lst l);

int		is_sorted(t_lst l);

void	three_sort(t_lst a);

void	build_lst_from_args(t_lst a, int argc, char **argv);

void	build_lst_from_str(t_lst a, char **argv);

int		rot_or_rrot(t_lst l);

int		midpoint(t_lst l);

void	push_swap0(t_lst a, t_lst b);

void	push_swap1(t_lst a, t_lst b, int j);

void	push_swap2(t_lst a, t_lst b, int j);

int		abs(int x);

int		max(int a, int b);

int		min(int a, int b);

int		is_min(t_lst a, int min);

int		is_max(t_lst a, int max);

int		ft_atoi(const char *str);

int		ft_strncmp(const char *s1, const char *s2, int n);

int		ft_strlen(const char *s);

int		is_space(const char c);

void	sort(int *a, int size);

int		non_integer(int argc, char **argv);

#endif
