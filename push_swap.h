/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:09:32 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/21 20:59:01 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "lists.h"
# include <limits.h>
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

void				solve(t_push_swap *ps);
void				optimize_instructions(t_list *lst);
t_pivots			*get_pivots(t_stack *stack, int pivots_count);
void				push(t_push_swap *ps, t_pivots *pivots);
void				pull(t_push_swap *ps);
int					free_and_exit(int *input, t_push_swap *instance);
int					init_datastructures(int *arr, int size,
						t_push_swap *instance);

int					*parse(int ac, char **av);
int					has_duplicates(int *input, int len);
int					number_too_big(int *input, int len);
int					check_input(int ac, char **av);

t_move				get_biggest(t_stack *stack);
t_move				get_smallest(t_stack *stack);

#endif