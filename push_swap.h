/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:59:49 by psaengha          #+#    #+#             */
/*   Updated: 2023/08/25 13:02:28 by psaengha         ###   ########.fr       */
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
// void	check_zero(int ac, char **av);
void	check_sorted(t_stack *a);
void	check_allerrors(int ac, char **av);
int		digitlen(char *str);

#endif
