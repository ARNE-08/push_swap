/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:50:05 by psaengha          #+#    #+#             */
/*   Updated: 2023/09/02 14:37:19 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_nextsmallest(t_stack *st)
{
	t_stack	*ptr;
	int		smallest;

	ptr = st;
	smallest = find_biggest(st);
	while (ptr)
	{
		if (ptr->index == 0 && ptr->value < smallest)
			smallest = ptr->value;
		ptr = ptr->next;
	}
	return (smallest);
}

void	setzero(t_stack **a)
{
	t_stack	*ptr;

	ptr = *a;
	while (ptr)
	{
		ptr->index = 0;
		ptr = ptr->next;
	}
	gotohead(a);
}

void	edit_index(t_stack **a)
{
	int		smallest;
	int		index;
	t_stack	*ptr;

	smallest = find_smallest(*a);
	index = 1;
	while (index != countnode(*a))
	{
		ptr = *a;
		while (ptr)
		{
			if (ptr->value == smallest)
				ptr->index = index;
			if (ptr->value == find_biggest(*a))
				ptr->index = countnode(*a);
			ptr = ptr->next;
		}
		index++;
		gotohead(a);
		smallest = find_nextsmallest(*a);
	}
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size_a;
	int	size_b;
	int	bit;

	bit = 1;
	while (isnotsorted(*a))
	{
		size_a = countnode(*a);
		while (size_a--)
		{
			if ((*a)->index & bit)
				ra(a);
			else
				pb(b, a);
		}
		size_b = countnode(*b);
		while (size_b--)
			pa(a, b);
		bit <<= 1;
	}
}
