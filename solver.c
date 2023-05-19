/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:18:50 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/19 19:14:18 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	partition(void)
// {

// }

void	solve_for_2(t_push_swap *ps)
{
	t_stack	*stack;

	stack = ps->stack_a;
	if (stack->data[stack->top] > stack->data[stack->top - 1])
		ra(ps);
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
	pivots->count = 6;
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
	if (top_idx == -1 && bot_idx == -1)
		return (-1);
	if (top_idx == -1)
		return (0);
	if (bot_idx == -1)
		return (1);
	if (bot_idx < (stack->top - top_idx))
		return (1);
	return (0);
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
		if (a->data[i] > pivot.min && a->data[i] < pivot.max)
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
		if (a->data[i] > pivot.min && a->data[i] < pivot.max)
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
int	get_biggest_idx(t_stack *stack)
{
	int	i;
	int	biggest_idx;

	i = 0;
	biggest_idx = INT_MIN;
	while (i < stack->top)
	{
		if (stack->data[i] > biggest_idx)
			biggest_idx = stack->data[i];
		i++;
	}
	return (biggest_idx);
}

/**
 * @brief Push back elements in A from biggest to smallest
 * 
 * @param ps 
 */
void	push_back(t_push_swap *ps)
{
	int	biggest_idx;

	while (ps->stack_b->top >= 0)
	{
		biggest_idx = get_biggest_idx(ps->stack_a);
		while (ps->stack_b->data[ps->stack_b->top] != biggest_idx)
		{
			// if (optimal_move(ps->stack_b, biggest_idx) == 1)
			// 	rb(ps);
			// else
			rrb(ps);
		}
		if (ps->stack_b->data[ps->stack_b->top] == biggest_idx)
			pa(ps);
	}
}

int	has_moves(t_move top, t_move bot)
{
	return (top.n > -1 && bot.n > -1);
}

void	push_right(t_push_swap *ps, t_pivots *pivots)
{
	t_move	top_move;
	t_move	bottom_move;
	int		best_move;
	int		i;

	i = 0;
	// printf("stack_a: ");
	// print_arr(ps->stack_a->data, ps->stack_a->top + 1);
	// printf("\n");
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
			// printf("stack_a: ");
			// print_arr(ps->stack_a->data, ps->stack_a->top + 1);
			// printf("\n");
			// printf("top_move.index=%d top_move.n=%d\n", top_move.index,
			// 		top_move.n);
			// printf("bottom_move.index=%d bottom_move.n=%d\n", bottom_move.index,
			// 		bottom_move.n);
			// if (best_move == 1)
			// 	printf("BEST IS rra\n");
			// else if (best_move == 2)
			// 	printf("BEST IS ra\n");
			// printf("current pivot min=%d current pivot max=%d\n",
			// 		pivots->pivots[i].min,
			// 		pivots->pivots[i].max);
			if (best_move == 1)
			{
				while (ps->stack_a->data[ps->stack_a->top] != top_move.n)
				{
					// printf("rra\n");
					ra(ps);
				}
				pb(ps);
			}
			else if (best_move == 0)
			{
				while (ps->stack_a->data[ps->stack_a->top] != bottom_move.n)
				{
					// printf("ra\n");
					rra(ps);
				}
				pb(ps);
			}
			// printf("\nstack_b:");
			// print_arr(ps->stack_b->data, ps->stack_b->top + 1);
			// printf("\n");
		}
		// check b before pushing it may need rotating in order to keep the numbers tied to their pivots
		i++;
	}
}

void	sort_large_input(t_push_swap *ps, t_pivots *pivots)
{
	push_right(ps, pivots);
	// printf("\nstack_b:");
	// print_arr(ps->stack_b->data, ps->stack_b->top + 1);
	// printf("\n");
	// printf("after push right\n");
	// print_arr(ps->stack_b->data, ps->stack_b->top + 1);
	// push_back(ps);
}

void	solve(t_push_swap *ps)
{
	t_pivots	*pivots;

	if (ps->stack_a->size == 2)
		return (solve_for_2(ps));
	// if (ps->stack_a->size > 3)
	pivots = get_pivots(ps->stack_a);
	// for (int i = 0; i < pivots->count; i++)
	// {
	// 	printf("min%d\n", pivots->pivots[i].min);
	// 	printf("max%d\n", pivots->pivots[i].max);
	// 	printf("=====\n");
	// }
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
