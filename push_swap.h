/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:09:32 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/15 17:37:05 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "lists.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				*data;
	int				top;
	int				size;
}					t_stack;

typedef struct s_push_swap
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	t_list			*output;
}					t_push_swap;

void				sa(t_push_swap *ps);
void				sb(t_push_swap *ps);
void				pa(t_push_swap *ps);
void				pb(t_push_swap *ps);
void				ra(t_push_swap *ps);
void				rb(t_push_swap *ps);
void				rra(t_push_swap *ps);
void				rrb(t_push_swap *ps);

int					check_input(int ac, char **av);
int					*parse(int ac, char **av);
void				print_arr(int *arr, int size);
void				solve(t_push_swap *pushswap);

#endif