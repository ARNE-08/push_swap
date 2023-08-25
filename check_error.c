/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:30:23 by psaengha          #+#    #+#             */
/*   Updated: 2023/08/25 13:05:39 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_emptystring(int ac, char **av)
{
	int	i;
	int	j;
	int	num;

	i = 1;
	num = 0;
	while (i < ac)
	{
		j = 0;
		num = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				num++;
			j++;
		}
		if (num == 0)
		{
			ft_printf("Error1\n");
			exit(0);
		}
		i++;
	}
}

void	check_sorted(t_stack *a)
{
	t_stack	*ptr;
	int		check;

	ptr = a;
	check = 0;
	while (ptr->next)
	{
		if (ptr->value > ptr->next->value)
			check = 1;
		ptr = ptr->next;
	}
	if (check == 0)
		exit(0);
}

void	check_allerrors(int ac, char **av)
{
	check_emptystring(ac, av);
	check_nonnumeric(ac, av);
	check_limit(ac, av);
}
