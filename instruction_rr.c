/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:36:23 by psaengha          #+#    #+#             */
/*   Updated: 2023/09/02 14:36:13 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **head)
{
	t_stack	*last;
	t_stack	*newtail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = *head;
	(*head)->prev = last;
	*head = last;
	newtail = last->prev;
	last->prev = NULL;
	newtail->next = NULL;
	ft_printf("rra\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*newtail;

	poptostack(a, b, 0);
	last = *a;
	while (last->next)
		last = last->next;
	last->next = *a;
	(*a)->prev = last;
	*a = last;
	newtail = last->prev;
	last->prev = NULL;
	newtail->next = NULL;
	ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*last;
	t_stack	*newtail;

	poptostack(a, b, 1);
	last = *b;
	while (last->next)
		last = last->next;
	last->next = *b;
	(*b)->prev = last;
	*b = last;
	newtail = last->prev;
	last->prev = NULL;
	newtail->next = NULL;
	ft_printf("pb\n");
}
