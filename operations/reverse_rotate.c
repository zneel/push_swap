/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:16:12 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/13 23:17:07 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 
 * reverse rotate a
 * Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * @param stack_a 
 */
void	rra(t_stack *stack_a, int print)
{
	int	i;
	int	last;

	if (stack_a->top <= 0)
		return ;
	i = stack_a->top - 1;
	last = stack_a->data[stack_a->top - 1];
	while (i-- > 0)
		stack_a->data[i] = stack_a->data[i - 1];
	stack_a->data[0] = last;
	if (print)
		ft_putendl_fd("rra", 1);
}

/**
 * @brief 
 * reverse rotate b
 * Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 * @param stack_b 
 */
void	rrb(t_stack *stack_b, int print)
{
	int	i;
	int	last;

	if (stack_b->top <= 0)
		return ;
	i = stack_b->top - 1;
	last = stack_b->data[stack_b->top - 1];
	while (i-- > 0)
		stack_b->data[i] = stack_b->data[i - 1];
	stack_b->data[0] = last;
	if (print)
		ft_putendl_fd("rrb", 1);
}

/**
 * @brief 
 * rra and rrb at the same time.
 * @param stack_a 
 * @param stack_b
 */
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_putendl_fd("rrr", 1);
}
