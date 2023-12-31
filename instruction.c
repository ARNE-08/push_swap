/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:04:28 by psaengha          #+#    #+#             */
/*   Updated: 2023/09/02 14:36:20 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **st)
{
	int		temp;
	t_stack	*node1;
	t_stack	*node2;

	if (*st != NULL && (*st)->next != NULL)
	{
		node1 = *st;
		node2 = (*st)->next;
		node1->next = node2->next;
		if (node2->next != NULL)
			node2->next->prev = node1;
		node2->prev = NULL;
		node2->next = node1;
		node1->prev = node2;
		temp = node1->index;
		node1->index = node2->index;
		node2->index = temp;
		*st = node2;
	}
	ft_printf("sa\n");
}

void	sb(t_stack **st)
{
	int		temp;
	t_stack	*node1;
	t_stack	*node2;

	if (*st != NULL && (*st)->next != NULL)
	{
		node1 = *st;
		node2 = (*st)->next;
		node1->next = node2->next;
		if (node2->next != NULL)
			node2->next->prev = node1;
		node2->prev = NULL;
		node2->next = node1;
		node1->prev = node2;
		temp = node1->index;
		node1->index = node2->index;
		node2->index = temp;
		*st = node2;
	}
	ft_printf("sb\n");
}

void	ra(t_stack **st)
{
	t_stack	*ptr;
	t_stack	*head;
	t_stack	*newhead;

	ptr = *st;
	if (ptr != NULL && ptr->next != NULL)
	{
		head = *st;
		newhead = (*st)->next;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = head;
		head->next = NULL;
		head->prev = ptr;
		*st = newhead;
	}
	(*st)->prev = NULL;
	ft_printf("ra\n");
}

void	rb(t_stack **st)
{
	t_stack	*ptr;
	t_stack	*head;
	t_stack	*newhead;

	ptr = *st;
	if (ptr != NULL && ptr->next != NULL)
	{
		head = *st;
		newhead = (*st)->next;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = head;
		head->next = NULL;
		head->prev = ptr;
		*st = newhead;
		reindex(st);
	}
	ft_printf("rb\n");
}
