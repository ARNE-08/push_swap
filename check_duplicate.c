/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:11:16 by psaengha          #+#    #+#             */
/*   Updated: 2023/08/25 11:22:45 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ! segment fault
int	havespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	numchar(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
		i++;
	return (i);
}

void	push_check(t_stack **a, int ac, char **av)
{
	int		i;
	int		j;
	int		index;
	char	**temp1;

	index = 0;
	i = 1;
	while (i < ac)
	{
		if (havespace(av[i]))
		{
			temp1 = ft_split(av[i], ' ');
			j = 0;
			while (j < numchar(temp1))
			{
				push(a, ft_atoi(temp1[j]), index);
				j++;
			}
		}
		else
			push(a, ft_atoi(av[i]), index);
		i++;
		index++;
	}
}

void	check_duplicate(t_stack *a)
{
	t_stack	*ptr;
	t_stack	*run;

	ptr = a;
	while (ptr)
	{
		run = ptr->next;
		while (run)
		{
			if (ptr->value == run->value)
			{
				ft_printf("Error\n");
				exit(0);
			}
			run = run->next;
		}
		ptr = ptr->next;
	}
}

// ! function to clear all stack
void	clear_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
