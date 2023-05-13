/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:15:24 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/13 23:20:30 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 
 * Push a
 * Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 * @param stack_b 
 * @param stack_a 
 */
void	pa(t_stack *stack_b, t_stack *stack_a)
{
	int	b_top;
	int	a_top;
	int	element;

	b_top = stack_b->top - 1;
	a_top = stack_a->top - 1;
	if (b_top > 0)
	{
		element = stack_b->data[b_top];
		stack_a->data[++a_top] = element;
		stack_b->top--;
		stack_a->top++;
		ft_putendl_fd("pa", 1);
	}
}

/**
 * @brief 
 * Push b
 * Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 * @param stack_a 
 * @param stack_b 
 */
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int a_top;
	int b_top;
	int element;

	a_top = stack_a->top - 1;
	b_top = stack_b->top - 1;
	if (a_top > 0)
	{
		element = stack_a->data[a_top];
		stack_b->data[++b_top] = element;
		stack_a->top--;
		stack_b->top++;
		ft_putendl_fd("pb", 1);
	}
}