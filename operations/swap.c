/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:14:45 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/13 23:17:14 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 
 * Swap a
 * Swap the first 2 elements at the top of stack a
 * Do nothing if there is only one or no elements.
 * @param stack_a 
 */
void	sa(t_stack *stack_a, int print)
{
	int	top;
	int	tmp;

	top = stack_a->top - 1;
	if (stack_a->top > 0)
	{
		tmp = stack_a->data[top];
		stack_a->data[top] = stack_a->data[top - 1];
		stack_a->data[top - 1] = tmp;
		if (print)
			ft_putendl_fd("sa", 1);
	}
}

/**
 * @brief 
 * Swap b
 * Swap the first 2 elements at the top of stack b
 * Do nothing if there is only one or no elements.
 * @param stack_b 
 */
void	sb(t_stack *stack_b, int print)
{
	int	top;
	int	tmp;

	top = stack_b->top - 1;
	if (stack_b->top > 0)
	{
		tmp = stack_b->data[top];
		stack_b->data[top] = stack_b->data[top - 1];
		stack_b->data[top - 1] = tmp;
		if (print)
			ft_putendl_fd("sb", 1);
	}
}

/**
 * @brief 
 * swap a and b at the same time
 * @param stack_a 
 * @param stack_b 
 */
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top > 1 && stack_b->top > 1)
	{
		sa(stack_a, 0);
		sb(stack_b, 0);
		ft_putendl_fd("ss", 1);
	}
}