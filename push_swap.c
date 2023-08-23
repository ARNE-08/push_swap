/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:49:10 by psaengha          #+#    #+#             */
/*   Updated: 2023/06/17 23:49:10 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// recieve a number as an argument. The first argument will 
// be put at the top of the stack
// use ft_split to handle when argument is "2 5 4 8 5 6 8"
// pop mode 0 is pa, mode 1 is pb

// create stack A
void	pushav(char **av, t_stack **st)
{
	int	i;
	int	j;
	int	value;

	i = 1;
	j = 0;
	while (av[i])
	{
		value = ft_atoi(av[i]);
		push(st, value, j);
		i++;
		j++;
	}
}

void	poptostack(t_stack **A, t_stack **B, int mode)
{
	if (mode == 0)
	{
		popto(B, A);
		reindex(A);
	}
	else
	{
		popto(A, B);
		reindex(B);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stackA;
	//t_stack	*stackB;

	(void)ac;
	stackA = NULL;
	//stackB = NULL;
	pushav(av, &stackA);

	t_stack *ptr = stackA;
	printf("Digits : %d\n", countmaxdigit(&stackA));
	while (ptr != NULL) {
		printf("Value: %d, Index: %d\n", ptr->value, ptr->index);
		ptr = ptr->next;
	}

	radix_sort(&stackA);

	//radix_sort(&stackA);
	//swap(&stackA);
	//ptr = stackA;
	//while (ptr != NULL) {
	//	printf("After swap Value: %d, Index: %d\n", ptr->value, ptr->index);
	//	ptr = ptr->next;
	//}

	//rotate(&stackA);
	//ptr = stackA;
	//while (ptr != NULL) {
	//	printf("After rotate Value: %d, Index: %d\n", ptr->value, ptr->index);
	//	ptr = ptr->next;
	//}

	// Free the memory allocated for the list
	//ptr = stackA;
	//while (ptr != NULL) {
	//	t_stack *temp = ptr;
	//	ptr = ptr->next;
	//	free(temp);
	//}

	//push to B
	//poptostack(&stackA, &stackB, 1);
	//ptr = stackB;
	//t_stack *ptrA = stackA;
	//while (ptr != NULL) {
	//	printf("StackB Value: %d, Index: %d\n", ptr->value, ptr->index);
	//	ptr = ptr->next;
	//}
	//while (ptrA != NULL) {
	//	printf("StackA Value: %d, Index: %d\n", ptrA->value, ptrA->index);
	//	ptrA = ptrA->next;
	//}
	//push to A
	//poptostack(&stackA, &stackB, 0);
	//ptr = stackA;
	//ptrA = stackB;
	//while (ptr != NULL) {
	//	printf("StackA Value: %d, Index: %d\n", ptr->value, ptr->index);
	//	ptr = ptr->next;
	//}
	//while (ptrA != NULL) {
	//	printf("StackB Value: %d, Index: %d\n", ptrA->value, ptrA->index);
	//	ptrA = ptrA->next;
	//}

	// check normal split
	// int index;
	// char **split;

	// (void)ac;
	// split = ft_split(av[1], ' ');
	// index = 0;
	// while (split[index])
	// {
	//     printf("%s\n", split[index]);
	//     index++;
	// }

	//check push to stack
	//t_stack *head = NULL;

	//// Add nodes to the list using the push function
	//push(&head, 5, 1);
	//push(&head, 10, 2);
	//push(&head, 15, 3);

	//// Print the values in the list
	//t_stack *ptr = head;
	//while (ptr != NULL) {
	//	printf("Value: %d, Index: %d\n", ptr->value, ptr->index);
	//	ptr = ptr->next;
	//}

	//// Free the memory allocated for the list
	//ptr = head;
	//while (ptr != NULL) {
	//	t_stack *temp = ptr;
	//	ptr = ptr->next;
	//	free(temp);
	//}
}