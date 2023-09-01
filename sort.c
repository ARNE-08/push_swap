/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:26:02 by psaengha          #+#    #+#             */
/*   Updated: 2023/08/29 22:28:41 by psaengha         ###   ########.fr       */
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

void    sort_3(t_stack **a)
{
    int biggest;
    int sort;

    biggest = find_biggest(*a);
    if ((*a)->value == biggest)
        ra(a);
    else if ((*a)->next->value == biggest)
        rra(a);
    if (isnotsorted(*a))
        sa(a);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int		smallest;
	int		i;

	smallest = find_smallest(*a);
	i = 0;
	while (i < 2)
	{
		while ((*a)->next)
		{
			if (smallest == (*a)->value)
				poptostack(a, b, 1);
			(*a) = (*a)->next;
		}
		if (smallest == (*a)->value)
			poptostack(a, b, 1);
		gotohead(a);
		reindex(a);
		smallest = find_smallest(*a);
		i++;
	}
	sort_3(a);
	*b = (*b)->next;
	pa(a, b);
	gotohead(b);
	reindex(b);
	pa(a, b);
}