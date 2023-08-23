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

# include "Libft/libft.h"
# include <limits.h>
# include <stdio.h>
// for stuff like INT_MAX and etc.

typedef struct s_stack {
    int                         value;
    int                         index;
    struct s_stack_linked_list  *prev;
    struct s_stack_linked_list  *next;
}   t_stack;

void    check_emptyString(int ac, char **av);
void    check_nonNumeric(int ac, char **av);

#endif