/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:36:23 by psaengha          #+#    #+#             */
/*   Updated: 2023/08/29 22:09:53 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void rra(t_stack **head)
{
    t_stack *last;
    t_stack *newTail;

    if (*head == NULL || (*head)->next == NULL)
        return ;
    last = *head;
    while (last->next) {
        last = last->next;
    }
    last->next = *head;
    (*head)->prev = last;
    *head = last;
    newTail = last->prev;
    last->prev = NULL;
    newTail->next = NULL;
    reindex(head);
    ft_printf("rra\n");
}

void    pa(t_stack **a, t_stack **b)
{
    t_stack *last;
    t_stack *newTail;
    
    poptostack(a, b, 0);
    //printf("hey\n");
    if (*a == NULL || (*a)->next == NULL)
        return ;
    last = *a;
    while (last->next) {
        last = last->next;
    }
    last->next = *a;
    (*a)->prev = last;
    *a = last;
    newTail = last->prev;
    last->prev = NULL;
    newTail->next = NULL;
    reindex(a);
    ft_printf("pa\n");
}