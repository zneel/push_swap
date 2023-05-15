/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:14:45 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/15 17:14:34 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 
 * Swap a
 * Swap the first 2 elements at the top of stack
 * Do nothing if there is only one or no elements.
 * @param stack
 */
int	swap(t_stack *stack)
{
	int	top;
	int	tmp;

	top = stack->top;
	if (stack->top > 0)
	{
		tmp = stack->data[top];
		stack->data[top] = stack->data[top - 1];
		stack->data[top - 1] = tmp;
		return (1);
	}
	return (0);
}

/**
 * @brief 
 * Swap a
 * Swap the first 2 elements at the top of stack a
 * Do nothing if there is only one or no elements.
 * @param stack_a 
 */
void	sa(t_push_swap *ps)
{
	t_list	*node;

	if (swap(ps->stack_a))
	{
		node = ft_lstnew(ft_strdup("sa\n"));
		if (!node)
			return ;
		ft_lstadd_back(&ps->output, node);
	}
}

/**
 * @brief 
 * Swap b
 * Swap the first 2 elements at the top of stack b
 * Do nothing if there is only one or no elements.
 * @param stack_b 
 */
void	sb(t_push_swap *ps)
{
	t_list	*node;

	if (swap(ps->stack_b))
	{
		node = ft_lstnew(ft_strdup("sb\n"));
		if (!node)
			return ;
		ft_lstadd_back(&ps->output, node);
	}
}
