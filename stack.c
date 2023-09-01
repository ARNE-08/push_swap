/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:59:41 by psaengha          #+#    #+#             */
/*   Updated: 2023/08/29 21:13:07 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reindex(t_stack **st)
{
	t_stack	*ptr;
	int		newindex;

	ptr = *st;
	newindex = 0;
	while (ptr != NULL)
	{
		ptr->index = newindex;
		newindex++;
		ptr = ptr->next;
	}
}

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