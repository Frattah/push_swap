/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:45:12 by frmonfre          #+#    #+#             */
/*   Updated: 2023/04/13 08:46:44 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <unistd.h>

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

t_lst	lst_init(char id);

void	lst_print(t_lst l);

void	lst_ins_back(t_lst l, int v);

void	is_sorted(t_lst a);

void	rot(t_lst l);

void	double_rot(t_lst a, t_lst b);

void	rrot(t_lst l);

void	double_rrot(t_lst a, t_lst b);

void	swap(t_lst l);

void	push(t_lst a, t_lst b);

void	calc_moves_b(t_lst a, t_lst b);

int		calc_moves_a(t_lst a, int num);

void	choice_move(t_lst a, t_lst b);

int		abs(int x);

int		max(int a, int b);

int		min(int a, int b);

int		is_min(t_lst a, int min);

int		is_max(t_lst a, int max);

void	push_swap0(t_lst a, t_lst b, int ln);

void	push_swap1(t_lst a, t_lst b, int index);

void	push_swap2(t_lst a, t_lst b, int index);

int		rot_or_rrot(t_lst l);

int		midpoint(t_lst l);

int		duplicates(t_lst a);

int		ft_atoi(const char *str);

char	**ft_split(char const *s, char c);

int		ft_strlen(const char *s);

int		is_space(char c);

void	lst_del(t_lst l);

int		non_integer(int argc, char **argv)

#endif
