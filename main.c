/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:49:10 by psaengha          #+#    #+#             */
/*   Updated: 2023/08/25 13:05:35 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// recieve a number as an argument. The first argument will
// be put at the top of the stack
// use ft_split to handle when argument is "2 5 4 8 5 6 8"
// pop mode 0 is pa, mode 1 is pb

// create stack A
//void	pushav(char **av, t_stack **st)
//{
//	int	i;
//	int	j;
//	int	value;

//	i = 1;
//	j = 0;
//	while (av[i])
//	{
//		value = ft_atoi(av[i]);
//		push(st, value, j);
//		i++;
//		j++;
//	}
//}

//void	poptostack(t_stack **A, t_stack **B, int mode)
//{
//	if (mode == 0)
//	{
//		popto(B, A);
//		reindex(A);
//	}
//	else
//	{
//		popto(A, B);
//		reindex(B);
//	}
//}

void	printall(t_stack *a)
{
	t_stack	*ptr;

	ptr = a;
	while (ptr)
	{
		printf("%d\n", ptr->value);
		ptr = ptr->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		exit(0);
	check_allerrors(ac, av);
	push_check(&a, ac, av);
	check_duplicate(a);
	check_sorted(a);
	clear_stack(&a);
	ft_printf("Yeah\n");
}
