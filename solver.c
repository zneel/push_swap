/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:18:50 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/17 23:26:05 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/**
 * @brief Generate n numbers of pivots from min max
 * 
 * @param min 
 * @param max 
 * @return t_pivots* 
 */
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

/**
 * @brief 
 * Get the optimal way of getting n to the top
 * @param a t_stack ptr
 * @param n index of the number inside the stack
 * @return 1 if the number is closer to the top (rotate)
 */
int	optimal_move(t_stack *stack, int n)
{
	return (n > stack->top / 2);
}

/**
 * @brief Get the first number thats less than
 * the pivot starting from the top of the stack
 * @param a 
 * @param pivot 
 * @return t_move 
 */
t_move	get_number_from_top(t_stack *a, int pivot)
{
	t_move	move;
	int		i;

	i = a->top;
	while (i)
	{
		if (a->data[i] < pivot)
		{
			move.index = i;
			move.n = a->data[i];
			break ;
		}
		i--;
	}
	return (move);
}

/**
 * @brief Get the first number thats less than the 
 * pivot starting from the bottom of the stack
 * @param a 
 * @param pivot 
 * @return t_move 
 */
t_move	get_number_from_bottom(t_stack *a, int pivot)
{
	t_move	move;
	int		i;

	i = 0;
	while (i < a->top)
	{
		if (a->data[i] < pivot)
		{
			move.index = i;
			move.n = a->data[i];
			break ;
		}
		i++;
	}
	return (move);
}

/**
 * @brief Get the idx of n in stack
 * 
 * @param stack 
 * @param n 
 * @return int 
 */
int	get_number_idx(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->data[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Get the biggest number index in stack
 * 
 * @param stack 
 * @return int 
 */
int	get_biggest(t_stack *stack)
{
	int	i;
	int	biggest;

	i = 0;
	biggest = INT_MIN;
	while (i < stack->top)
	{
		if (stack->data[i] > biggest)
			biggest = stack->data[i];
		i++;
	}
	return (biggest);
}

/**
 * @brief Push back elements in A from biggest to smallest
 * 
 * @param ps 
 */
void	push_back(t_push_swap *ps)
{
	int	biggest;

	while (ps->stack_b->top >= 0)
	{
		biggest = get_biggest(ps->stack_a);
		while (ps->stack_b->data[ps->stack_b->top] != biggest)
		{
			if (optimal_move(ps->stack_b, biggest))
				rb(ps);
			else
				rrb(ps);
		}
		if (ps->stack_b->data[ps->stack_b->top] == biggest)
			pa(ps);
	}
}

void	push_right(t_push_swap *ps, t_pivots *pivots)
{
	t_move	top_move;
	t_move	bottom_move;
	int		i;

	i = 0;
	while (i < pivots->count)
	{
		top_move = get_number_from_top(ps->stack_a, pivots->pivots[i]);
		bottom_move = get_number_from_bottom(ps->stack_a,
				pivots->pivots[i]);
		printf("optimal move = %s\n", optimal_move(ps->stack_a, top_move.index) ? "RA" : "RRA");
		if (optimal_move(ps->stack_a, top_move.index))
			while (ps->stack_a->data[ps->stack_a->top] != bottom_move.n)
				ra(ps);
		else
			while (ps->stack_a->data[ps->stack_a->top] != bottom_move.n)
				rra(ps);
		pb(ps); // check b before pushing it may need rotating in order to keep the numbers tied to their pivots
	}
	i++;
}

void	sort_large_input(t_push_swap *ps, t_pivots *pivots)
{
	push_right(ps, pivots);
	push_back(ps);
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
