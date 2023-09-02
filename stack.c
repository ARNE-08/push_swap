/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:59:41 by psaengha          #+#    #+#             */
/*   Updated: 2023/09/02 14:37:49 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reindex(t_stack **st)
{
	t_stack	*ptr;
	int		newindex;

	gotohead(st);
	ptr = *st;
	newindex = 0;
	while (ptr != NULL)
	{
		ptr->index = newindex;
		newindex++;
		ptr = ptr->next;
	}
}

void	gotohead(t_stack **st)
{
	while ((*st)->prev)
		*st = (*st)->prev;
}

void	gototail(t_stack **st)
{
	while ((*st)->next)
		*st = (*st)->next;
}

int	find_biggest(t_stack *st)
{
	t_stack	*ptr;
	int		biggest;

	ptr = st;
	biggest = ptr->value;
	while (ptr)
	{
		if (ptr->value > biggest)
			biggest = ptr->value;
		ptr = ptr->next;
	}
	return (biggest);
}

int	find_smallest(t_stack *st)
{
	t_stack	*ptr;
	int		smallest;

	ptr = st;
	smallest = ptr->value;
	while (ptr)
	{
		if (ptr->value < smallest)
			smallest = ptr->value;
		ptr = ptr->next;
	}
	return (smallest);
}
