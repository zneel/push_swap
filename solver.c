/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:18:50 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/20 00:07:50 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_for_2(t_push_swap *ps)
{
	t_stack	*stack;

	stack = ps->stack_a;
	if (stack->data[stack->top] > stack->data[stack->top - 1])
		ra(ps);
}

/**
 * @brief Generate n numbers of pivots from min max
 * 
 * @param	stack
 * @return	*pivots 
 */
t_pivots	*get_pivots(t_stack *stack)
{
	t_pivots	*pivots;
	int			step;
	int			i;

	i = 0;
	pivots = malloc(sizeof(t_pivots));
	if (!pivots)
		return (NULL);
	pivots->count = PIVOTS_COUNT;
	pivots->pivots = malloc(sizeof(t_pivot) * pivots->count);
	if (!pivots->pivots)
		return (free(pivots), NULL);
	step = stack->size / pivots->count;
	while (i < pivots->count)
	{
		if (i == 0)
			pivots->pivots[i].min = -1;
		else
			pivots->pivots[i].min = pivots->pivots[i - 1].max + 1;
		if (i == pivots->count - 1)
			pivots->pivots[i].max = stack->size;
		else
			pivots->pivots[i].max = (i + 1) * step;
		i++;
	}
	return (pivots);
}

/**
 * @brief 
 * Return if it cost less to move top or bot number to top
 * of stack
 * @param stack stack
 * @param top_idx idx of the top n in stack
 * @param bot_idx idx of the bot n in stack
 * @return 1 if top_idx cost less otherwise 0
 */
int	optimal_move(t_stack *stack, int top_idx, int bot_idx)
{
	int	top_steps;
	int	bot_steps;

	top_steps = stack->top - top_idx;
	bot_steps = bot_idx + 1;
	if (top_idx == -1 && bot_idx == -1)
		return (-1);
	if (top_idx == -1 || bot_steps < top_steps)
		return (0);
	if (bot_idx == -1 || top_steps <= bot_steps)
		return (1);
	return (-1);
}

/**
 * @brief Get the first number thats less than
 * the pivot starting from the top of the stack
 * @param a 
 * @param pivot 
 * @return t_move 
 */
t_move	from_top(t_stack *a, t_pivot pivot)
{
	t_move	move;
	int		i;

	i = a->top;
	move.index = -1;
	move.n = -1;
	while (i >= 0)
	{
		if (a->data[i] >= pivot.min && a->data[i] <= pivot.max)
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
t_move	from_bottom(t_stack *a, t_pivot pivot)
{
	t_move	move;
	int		i;

	i = 0;
	move.index = -1;
	move.n = -1;
	while (i <= a->top)
	{
		if (a->data[i] >= pivot.min && a->data[i] <= pivot.max)
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
 * @brief Get the biggest number index in stack
 * 
 * @param stack 
 * @return int 
 */
int	get_biggest_idx(t_stack *stack)
{
	int	i;
	int	biggest_n;
	int	biggest_idx;

	i = 0;
	biggest_idx = 0;
	biggest_n = INT_MIN;
	while (i <= stack->top)
	{
		if (stack->data[i] > biggest_n)
		{
			biggest_n = stack->data[i];
			biggest_idx = i;
		}
		i++;
	}
	return (biggest_idx);
}

/**
 * @brief Get the smallest number index in stack
 * 
 * @param stack 
 * @return int 
 */
int	get_smallest_idx(t_stack *stack)
{
	int	i;
	int	smallest_n;
	int	smallest_idx;

	i = 0;
	smallest_n = INT_MAX;
	smallest_idx = 0;
	while (i <= stack->top)
	{
		if (stack->data[i] < smallest_n)
		{
			smallest_n = stack->data[i];
			smallest_idx = i;
		}
		i++;
	}
	return (smallest_idx);
}

/**
 * @brief Push back elements in A from biggest to smallest
 * 
 * @param ps 
 */
void	push_back(t_push_swap *ps)
{
	int	biggest_idx;
	int	biggest;

	while (ps->stack_b->top >= 0)
	{
		biggest_idx = get_biggest_idx(ps->stack_b);
		biggest = ps->stack_b->data[biggest_idx];
		if (biggest_idx > ps->stack_b->top / 2)
			while (ps->stack_b->data[ps->stack_b->top] != biggest)
				rb(ps);
		else
			while (ps->stack_b->data[ps->stack_b->top] != biggest)
				rrb(ps);
		pa(ps);
	}
}

int	has_moves(t_move top, t_move bot)
{
	return (top.n > -1 && bot.n > -1);
}

int	rotate_stack_b(t_push_swap *ps)
{
	t_stack	*sb;
	int		smallest_idx;
	int		smallest;

	sb = ps->stack_b;
	if (sb->top < 0)
		return (1);
	smallest_idx = get_smallest_idx(sb);
	smallest = sb->data[smallest_idx];
	if (smallest_idx > sb->top / 2)
		while (sb->data[sb->top] != smallest)
			rb(ps);
	else
		while (sb->data[sb->top] != smallest)
			rrb(ps);
	return (1);
}

void	push_right(t_push_swap *ps, t_pivots *pivots)
{
	t_move	top_move;
	t_move	bottom_move;
	int		best_move;
	int		i;

	i = 0;
	while (i < pivots->count)
	{
		top_move.n = 1;
		bottom_move.n = 1;
		while (has_moves(top_move, bottom_move))
		{
			top_move = from_top(ps->stack_a, pivots->pivots[i]);
			bottom_move = from_bottom(ps->stack_a, pivots->pivots[i]);
			best_move = optimal_move(ps->stack_a, top_move.index,
					bottom_move.index);
			if (best_move == 1)
			{
				while (ps->stack_a->data[ps->stack_a->top] != top_move.n)
					ra(ps);
				// if (rotate_stack_b(ps))
				pb(ps);
			}
			else if (best_move == 0)
			{
				while (ps->stack_a->data[ps->stack_a->top] != bottom_move.n)
					rra(ps);
				// if (rotate_stack_b(ps))
				pb(ps);
			}
		}
		i++;
	}
}

void	sort_large_input(t_push_swap *ps, t_pivots *pivots)
{
	push_right(ps, pivots);
	push_back(ps);
}

void	solve(t_push_swap *ps)
{
	t_pivots	*pivots;

	if (ps->stack_a->size == 2)
		return (solve_for_2(ps));
	pivots = get_pivots(ps->stack_a);
	sort_large_input(ps, pivots);
	free(pivots->pivots);
	free(pivots);
}
