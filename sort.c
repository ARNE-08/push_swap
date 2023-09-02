/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:26:02 by psaengha          #+#    #+#             */
/*   Updated: 2023/09/02 00:59:02 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnotsorted(t_stack *a)
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
		return (0);
	return (1);
}

void	sort_3(t_stack **a)
{
	int	biggest;
	int	sort;

	biggest = find_biggest(*a);
	if ((*a)->value == biggest)
		ra(a);
	else if ((*a)->next->value == biggest)
		rra(a);
	if (isnotsorted(*a))
		sa(a);
}

void	pass_to_b(t_stack **a, t_stack **b, int smallest, int index)
{
	int	mid;

	mid = countnode(*a) / 2;
	reindex(a);
	if (index <= mid)
	{
		gotohead(a);
		while ((*a)->value != smallest)
		{
			gotohead(a);
			ra(a);
		}
	}
	else
	{
		gotohead(a);
		while ((*a)->value != smallest)
		{
			rra(a);
			gotohead(a);
		}
	}
}

void	sort_5sub(t_stack **a, t_stack **b, int smallest)
{
	while ((*a)->next)
	{
		if (smallest == (*a)->value)
		{
			if ((*a)->prev != NULL)
			{
				pass_to_b(a, b, smallest, (*a)->index);
				pb(b, a);
			}
			else
				pb(b, a);
		}
		(*a) = (*a)->next;
	}
	if (smallest == (*a)->value)
	{
		pass_to_b(a, b, smallest, (*a)->index);
		pb(b, a);
	}
	gotohead(a);
	reindex(a);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int		smallest;
	int		i;
	int		max;

	smallest = find_smallest(*a);
	i = 0;
	if (countnode(*a) < 5)
		max = 1;
	else
		max = 2;
	while (i < max)
	{
		sort_5sub(a, b, smallest);
		smallest = find_smallest(*a);
		i++;
	}
	sort_3(a);
	pa(a, b);
	if (max == 2)
	{
		gotohead(b);
		reindex(b);
		pa(a, b);
	}
}
