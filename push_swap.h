/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:09:32 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/20 16:13:36 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "lists.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

# define PIVOTS_COUNT 8

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

typedef struct s_pivot
{
	int				min;
	int				max;
}					t_pivot;
typedef struct s_pivots
{
	t_pivot			*pivots;
	int				count;
}					t_pivots;

typedef struct s_move
{
	int				n;
	int				index;
}					t_move;

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
void				solve(t_push_swap *ps);
void				optimize_instructions(t_list *lst);

#endif