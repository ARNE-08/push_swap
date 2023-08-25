/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nonlimit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:52:03 by psaengha          #+#    #+#             */
/*   Updated: 2023/08/25 13:04:59 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_innernnonnumeric(char *str)
{
	char	**temp1;
	int		j;
	int		i;

	temp1 = ft_split(str, ' ');
	j = 0;
	while (temp1[j])
	{
		i = 0;
		while (temp1[j][i])
		{
			if (i == 0 && (temp1[j][i] == '-' || temp1[i][j] == '+'))
				i++;
			if (temp1[j][i] < '0' || temp1[j][i] > '9')
			{
				ft_printf("Error2\n");
				exit(0);
			}
			i++;
		}
		j++;
	}
}

void	check_nonnumeric(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		if (havespace(av[i]))
			check_innernnonnumeric(av[i]);
		else
		{
			j = 0;
			while (av[i][j])
			{
				if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
					j++;
				if (av[i][j] < '0' || av[i][j] > '9')
				{
					ft_printf("Error2\n");
					exit(0);
				}
				j++;
			}
		}
		i++;
	}
}

int	digitlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[j] == '-')
		j++;
	while (str[j] != '\0')
	{
		i++;
		j++;
	}
	return (i);
}

void	check_innerlimit(char *str)
{
	int		j;
	char	**temp;

	temp = ft_split(str, ' ');
	j = 0;
	while (temp[j])
	{
		if (digitlen(temp[j]) > 10
			|| ft_atoi(temp[j]) > INT_MAX || ft_atoi(temp[j]) < INT_MIN)
		{
			ft_printf("Error7\n");
			exit(0);
		}
		j++;
	}
}

void	check_limit(int ac, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (havespace(av[i]))
			check_innerlimit(av[i]);
		else
		{
			if (digitlen(av[i]) > 10
				|| ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			{
				ft_printf("Error7\n");
				exit(0);
			}
		}
		i++;
	}
}
