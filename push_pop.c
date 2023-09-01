/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:28:00 by psaengha          #+#    #+#             */
/*   Updated: 2023/08/29 22:24:09 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **head, int value, int index)
{
	t_stack	*newnode;
	t_stack	*ptr;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
		return ;
	newnode->value = value;
	newnode->index = index;
	newnode->prev = NULL;
	newnode->next = NULL;
	if (*head == NULL)
		*head = newnode;
	else
	{
		ptr = *head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newnode;
		newnode->prev = ptr;
	}
}

void	popto(t_stack **src, t_stack **dest)
{
	push(dest, (*src)->value, (*src)->index);
	if ((*src)->prev != NULL)
	{
		(*src)->prev->next = (*src)->next;
		if ((*src)->next != NULL)
			(*src)->next->prev = (*src)->prev;
	}
	else
	{
		if ((*src)->next != NULL)
		{
			*src = (*src)->next;
			(*src)->prev = NULL;
		}
	}
}