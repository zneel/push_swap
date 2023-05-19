/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:16:20 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/19 22:31:30 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 
 * rotate x
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 * @param stack
 */
int	rotate(t_stack *stack)
{
	int	i;
	int	last;

	if (stack->top <= 0)
		return (0);
	i = stack->top;
	last = stack->data[stack->top];
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = last;
	return (1);
}

/**
 * @brief 
 * rotate a
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 * @param ps 
 */
void	ra(t_push_swap *ps)
{
	t_list	*node;

	if (rotate(ps->stack_a))
	{
		node = ft_lstnew(ft_strdup("ra\n"));
		if (!node)
			return ;
		ft_lstadd_back(&ps->output, node);
	}
}

/**
 * @brief 
 * rotate b
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 * @param stack_b 
 */
void	rb(t_push_swap *ps)
{
	t_list	*node;

	if (rotate(ps->stack_b))
	{
		node = ft_lstnew(ft_strdup("rb\n"));
		if (!node)
			return ;
		ft_lstadd_back(&ps->output, node);
	}
}
