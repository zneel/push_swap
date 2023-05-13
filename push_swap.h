/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:09:32 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/13 23:13:54 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
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
}					t_push_swap;

void				sa(t_stack *stack_a, int print);
void				sb(t_stack *stack_b, int print);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_b, t_stack *stack_a);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack *stack_a, int print);
void				rb(t_stack *stack_b, int print);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack_a, int print);
void				rrb(t_stack *stack_b, int print);
void				rrr(t_stack *stack_a, t_stack *stack_b);
int					check_input(int ac, char **av);
int					*parse(int ac, char **av);
void				print_arr(int *arr, int size);

#endif