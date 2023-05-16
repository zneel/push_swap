/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:18:50 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/16 22:52:26 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_min
{
	int		value;
	int		index;
}			t_min;

typedef struct s_max
{
	int		value;
	int		index;
}			t_max;

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

t_max	get_max(t_stack *stack)
{
	t_max	max;

	max.index = 0;
	max.value = INT_MIN;
	while (max.index <= stack->top)
	{
		if (stack->data[max.index] > max.value)
			max.value = stack->data[max.index];
		max.index++;
	}
	return (max);
}

// void	partition(void)
// {

// }

// void	solve_for_3(t_push_swap *ps)
// {
// }

// void	solve_for_5(t_push_swap *ps)
// {
// }

// void	solve_other(t_push_swap *ps)
// {
// }

t_pivots	*get_pivots(t_min min, t_max max)
{
	t_pivots	*pivots;
	int			step;
	int			i;

	i = 0;
	pivots = malloc(sizeof(t_pivots));
	if (!pivots)
		return (NULL);
	pivots->count = 3;
	pivots->pivots = malloc(sizeof(int) * pivots->count);
	if (!pivots->pivots)
		return (free(pivots), NULL);
	step = (max.value - min.value) / (pivots->count + 1);
	while (i < pivots->count)
	{
		pivots->pivots[i] = min.value + (i + 1) * step;
		i++;
	}
	return (pivots);
}

void	sort_pivots(t_push_swap *ps, t_pivots *pivots)
{
	int value;

	while (ps->stack_a->top)
	{
		value = ps->stack_a->data[ps->stack_a->top];
		if (value <= pivots->pivots[0])
			pb(ps);
		else if (value <= pivots->pivots[1])
		{
			while (ps->stack_b->top >= 0 && ps->stack_b->data[ps->stack_b->top] <= pivots->pivots[0])
                rb(ps);
			pb(ps);
		}
		else if(value <= pivots->pivots[2])
		{
			while (ps->stack_b->top >= 0 && ps->stack_b->data[ps->stack_b->top] <= pivots->pivots[1])
                rb(ps);
			pb(ps);
		}
		else
		{
			while (ps->stack_b->top >= 0 && ps->stack_b->data[ps->stack_b->top] <= pivots->pivots[2])
                rrb(ps);
			pb(ps);
		}
	}
}

void	sort_large_input(t_push_swap *ps, t_pivots *pivots)
{
	print_arr(ps->stack_a->data, ps->stack_a->size);
	sort_pivots(ps, pivots);
	// print_arr(ps->stack_b->data, ps->stack_b->top++);
}

void	solve(t_push_swap *ps)
{
	t_pivots	*pivots;
	t_min		min;
	t_max		max;

	min = get_min(ps->stack_a);
	max = get_max(ps->stack_a);
	pivots = get_pivots(min, max);
	// print_arr(pivots->pivots, pivots->count);
	sort_large_input(ps, pivots);
	free(pivots->pivots);
	free(pivots);
	// int	*sorted_input;
	// sorted_input = malloc(sizeof(int) * ps->stack_a->size);
	// if (!sorted_input)
	// 	return ;
	// ft_memcpy(sorted_input, input, sizeof(int) * (ps->stack_a->size));
	// quick_sort(sorted_input, 0, ps->stack_a->size - 1);
	// print_arr(sorted_input, ps->stack_a->size);
	// free(sorted_input);
}
