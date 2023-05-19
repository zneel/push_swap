/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:16:12 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/19 21:36:42 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack *stack)
{
	int	i;
	int	first;

	if (stack->top <= 0)
		return (0);
	i = 0;
	first = stack->data[0];
	while (i < stack->top)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->top] = first;
	return (1);
}

/**
 * @brief 
 * reverse rotate a
 * Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * @param stack_a 
 */
void	rra(t_push_swap *ps)
{
	t_list	*node;

	if (reverse_rotate(ps->stack_a))
	{
		node = ft_lstnew(ft_strdup("rra\n"));
		if (!node)
			return ;
		ft_lstadd_back(&ps->output, node);
	}
}

/**
 * @brief 
 * reverse rotate b
 * Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 * @param stack_b 
 */
void	rrb(t_push_swap *ps)
{
	t_list	*node;

	if (reverse_rotate(ps->stack_b))
	{
		node = ft_lstnew(ft_strdup("rrb\n"));
		if (!node)
			return ;
		ft_lstadd_back(&ps->output, node);
	}
}
