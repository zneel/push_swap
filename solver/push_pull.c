/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:18:01 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/21 14:19:41 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_moves(t_move top, t_move bot)
{
	return (top.n > -1 && bot.n > -1);
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

void	push(t_push_swap *ps, t_pivots *pivots)
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
				pb(ps);
			}
			else if (best_move == 0)
			{
				while (ps->stack_a->data[ps->stack_a->top] != bottom_move.n)
					rra(ps);
				pb(ps);
			}
		}
		i++;
	}
}

/**
 * @brief Push back elements in A from biggest to smallest
 * 
 * @param ps 
 */
void	pull(t_push_swap *ps)
{
    t_move biggest;

	while (ps->stack_b->top >= 0)
	{
		biggest = get_biggest(ps->stack_b);
		if (biggest.index > ps->stack_b->top / 2)
			while (ps->stack_b->data[ps->stack_b->top] != biggest.n)
				rb(ps);
		else
			while (ps->stack_b->data[ps->stack_b->top] != biggest.n)
				rrb(ps);
		pa(ps);
	}
}