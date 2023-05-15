/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:18:50 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/15 17:37:52 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_min
{
	int	value;
	int	index;
}		t_min;

t_min	get_min(t_stack *stack)
{
	t_min	min;

	min.index = 0;
	min.value = __INT_MAX__;
	while (min.index <= stack->top)
	{
		if (stack->data[min.index] < min.value)
			min.value = stack->data[min.index];
		min.index++;
	}
	return (min);
}

// void	solve_for_3(t_push_swap *ps)
// {
// }

// void	solve_for_5(t_push_swap *ps)
// {
// }

// void	solve_other(t_push_swap *ps)
// {
// }

void	solve(t_push_swap *pushswap)
{
	t_min min;
	while (pushswap->stack_a->top >= 0)
	{
		min = get_min(pushswap->stack_a);
		if (min.index < pushswap->stack_a->top / 2)
			while (pushswap->stack_a->data[0] != min.value)
				ra(pushswap);
		else
			while (pushswap->stack_a->data[0] != min.value)
				rra(pushswap);
		pb(pushswap);
	}
	while (pushswap->stack_a->top >= 0)
		pa(pushswap);
}
