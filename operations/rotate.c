/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:16:20 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/14 12:14:20 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 
 * rotate a
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 * @param stack_a 
 */
void	ra(t_stack *stack_a, int print)
{
	int	i;
	int	first;

	if (stack_a->top <= 0)
		return ;
	i = 0;
	first = stack_a->data[0];
	while (i < stack_a->top)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i++;
	}
	stack_a->data[stack_a->top] = first;
	if (print)
		ft_putendl_fd("ra", 1);
}

/**
 * @brief 
 * rotate b
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 * @param stack_b 
 */
void	rb(t_stack *stack_b, int print)
{
	int	i;
	int	first;

	if (stack_b->top <= 0)
		return ;
	i = 0;
	first = stack_b->data[0];
	while (i < stack_b->top)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		i++;
	}
	stack_b->data[stack_b->top] = first;
	if (print)
		ft_putendl_fd("rb", 1);
}

/**
 * @brief 
 * ra and rb at the same time
 * @param stack_a 
 * @param stack_b 
 */
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_putendl_fd("rr", 1);
}