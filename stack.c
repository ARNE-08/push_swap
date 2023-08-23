/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:59:41 by psaengha          #+#    #+#             */
/*   Updated: 2023/06/17 23:59:41 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_stack **head, int value, int index)
{
    t_stack *newNode;
    t_stack *ptr;

    newNode = (t_stack *)malloc(sizeof(t_stack));
    if (!newNode)
        return;
    newNode->value = value;
    newNode->index = index;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (*head == NULL)
        *head = newNode;
    else
    {
        ptr = *head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
        newNode->prev = ptr;
    }
}

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

void	popto(t_stack **src, t_stack **dest)
{
	t_stack	*ptr;

	ptr = *src;
	while (ptr->next != NULL)
		ptr = ptr->next;
	push(dest, ptr->value, ptr->index);
	if (ptr->prev != NULL)
		ptr->prev->next = NULL;
	else
		*src = NULL;
}