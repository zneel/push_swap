/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:18:50 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/21 14:22:46 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_for_2(t_push_swap *ps)
{
	t_stack	*stack;

	stack = ps->stack_a;
	if (stack->data[stack->top] > stack->data[stack->top - 1])
		sa(ps);
}

void	solve_for_3(t_push_swap *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->stack_a->data[2];
	b = ps->stack_a->data[1];
	c = ps->stack_a->data[0];
	if (a > b && a < c && b < a && b < c)
		sa(ps);
	else if (a > b && a > c && c < b)
	{
		sa(ps);
		rra(ps);
	}
	else if (a > b && a > c && b < c)
		ra(ps);
	else if (a < b && a < c && b > c)
	{
		sa(ps);
		ra(ps);
	}
	else if (a < b && b > a && b > c && c < a)
		rra(ps);
}

void	solve_for_5(t_push_swap *ps)
{
	t_stack	*a;
	t_stack	*b;
	t_move	min;

	a = ps->stack_a;
	b = ps->stack_b;
	while (a->top > 2)
	{
		min = get_smallest(a);
		while (a->data[a->top] != min.n)
		{
			if (min.index > a->top / 2)
				ra(ps);
			else
				rra(ps);
		}
		pb(ps);
	}
	solve_for_3(ps);
	if (b->data[b->top] < b->data[b->top - 1])
		sb(ps);
	pa(ps);
	pa(ps);
}

void	sort(t_push_swap *ps, t_pivots *pivots)
{
	push(ps, pivots);
	pull(ps);
}

void	solve(t_push_swap *ps)
{
	t_pivots	*pivots;

	if (ps->stack_a->size == 2)
		return (solve_for_2(ps));
	else if (ps->stack_a->size == 3)
		return (solve_for_3(ps));
	else if (ps->stack_a->size == 5)
		return (solve_for_5(ps));
	else if (ps->stack_a->size <= 100)
		pivots = get_pivots(ps->stack_a, 5);
	else if (ps->stack_a->size > 100)
		pivots = get_pivots(ps->stack_a, 13);
	sort(ps, pivots);
	return (
		free(pivots->pivots),
		free(pivots));
}
