/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:15:24 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/15 17:45:31 by ebouvier         ###   ########.fr       */
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
void	pa(t_push_swap *ps)
{
	int		element;
	int		a_top;
	int		b_top;
	t_list	*node;

	a_top = ps->stack_a->top;
	b_top = ps->stack_b->top;
	if (b_top >= 0)
	{
		node = ft_lstnew(ft_strdup("pa\n"));
		if (!node)
			return ;
		element = ps->stack_b->data[b_top];
		ps->stack_a->data[++a_top] = element;
		ps->stack_b->top--;
		ps->stack_a->top++;
		ft_lstadd_back(&ps->output, node);
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
void	pb(t_push_swap *ps)
{
	int element;
	int a_top;
	int b_top;
	t_list *node;

	a_top = ps->stack_a->top;
	b_top = ps->stack_b->top;
	if (a_top >= 0)
	{
		node = ft_lstnew(ft_strdup("pb\n"));
		if (!node)
			return ;
		element = ps->stack_a->data[a_top];
		ps->stack_b->data[++b_top] = element;
		ps->stack_a->top--;
		ps->stack_b->top++;
		ft_lstadd_back(&ps->output, node);
	}
}