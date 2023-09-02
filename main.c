/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:49:10 by psaengha          #+#    #+#             */
/*   Updated: 2023/09/02 14:37:56 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	countnode(t_stack *st)
{
	int		i;
	t_stack	*ptr;

	i = 0;
	ptr = st;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

void	doublefree(char **str)
{
	int	k;

	k = 0;
	while (str[k])
	{
		free(str[k]);
		k++;
	}
	free(str);
}

void	poptostack(t_stack **A, t_stack **B, int mode)
{
	if (mode == 0)
		popto(B, A);
	else
		popto(A, B);
}

void	sortstack(t_stack **a, t_stack **b)
{
	if (countnode(*a) == 2)
		sa(a);
	else if (countnode(*a) == 3)
		sort_3(a);
	else if (countnode(*a) <= 5)
		sort_5(a, b);
	else
	{
		setzero(a);
		edit_index(a);
		radix_sort(a, b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		sort;

	a = NULL;
	b = NULL;
	check_allerrors(ac, av);
	if (ac < 2 || (ac < 3 && !havespace(av[1])))
		exit(0);
	push_check(&a, ac, av);
	check_duplicate(a);
	check_sorted(a);
	reindex(&a);
	sortstack(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
}
