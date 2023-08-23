/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:59:49 by psaengha          #+#    #+#             */
/*   Updated: 2023/06/17 23:59:49 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>
// for stuff like INT_MAX and etc.

typedef struct s_stack_linked_list {
    int                         value;
    int                         index;
    struct s_stack_linked_list  *prev;
    struct s_stack_linked_list  *next;
}   t_stack;

void    push(t_stack **head, int value, int index);
char	**ft_split(char const *s, char c);
int     ft_atoi(const char *str);
void	swap(t_stack **st);
void	rotate(t_stack **st);
void	reindex(t_stack **st);
void	popto(t_stack **src, t_stack **dest);
int     countmaxdigit(t_stack **st);
void    radix_sort();

#endif