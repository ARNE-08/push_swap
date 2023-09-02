/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:59:49 by psaengha          #+#    #+#             */
/*   Updated: 2023/09/02 14:37:12 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/libft/libft.h"
# include "utils/ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
// for stuff like INT_MAX and etc.

typedef struct s_stack {
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void	check_emptystring(int ac, char **av);
void	check_nonnumeric(int ac, char **av);
void	check_duplicate(t_stack *a);
void	check_limit(int ac, char **av);
void	push_check(t_stack **a, int ac, char **av);
void	push(t_stack **head, int value, int index);
void	clear_stack(t_stack **stack);
int		havespace(char *str);
void	check_sorted(t_stack *a);
void	check_allerrors(int ac, char **av);
int		digitlen(char *str);
void	sa(t_stack **st);
void	sb(t_stack **st);
int		countnode(t_stack *st);
void	gotohead(t_stack **st);
void	gototail(t_stack **st);
void	ra(t_stack **st);
void	rb(t_stack **st);
int		find_biggest(t_stack *st);
void	rra(t_stack **head);
void	sort_3(t_stack **a);
void	printall(t_stack *a);
int		find_smallest(t_stack *st);
void	poptostack(t_stack **A, t_stack **B, int mode);
void	popto(t_stack **src, t_stack **dest);
void	sort_5(t_stack **a, t_stack **b);
void	reindex(t_stack **st);
void	pa(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b);
int		isnotsorted(t_stack *a);
void	pb(t_stack **a, t_stack **b);
void	edit_index(t_stack **a);
void	setzero(t_stack **a);
void	doublefree(char **str);

#endif
