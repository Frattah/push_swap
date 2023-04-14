/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:22:04 by frmonfre          #+#    #+#             */
/*   Updated: 2023/04/14 09:50:31 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	meno;

	meno = 1;
	nb = 0;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (!ft_strncmp(str + i, "-2147483648", 12))
		return (-2147483648);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			meno *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb > 2147483647 / 10 || nb * 10 > 2147483647 - str[i] + '0')
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		nb = (nb * 10) + str[i++] - '0';
	}
	return (meno * nb);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	is_space(const char c)
{
	return (c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	non_integer(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9')
				&& !is_space(argv[i][j]) && argv[i][j] != '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
