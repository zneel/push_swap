/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_small_getters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:23:57 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/21 13:50:28 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Get the biggest number index in stack
 * 
 * @param stack 
 * @return t_move 
 */
t_move	get_biggest(t_stack *stack)
{
	int		i;
	t_move	biggest;

	i = 0;
	biggest.index = 0;
	biggest.n = INT_MIN;
	while (i <= stack->top)
	{
		if (stack->data[i] > biggest.n)
		{
			biggest.n = stack->data[i];
			biggest.index = i;
		}
		i++;
	}
	return (biggest);
}

/**
 * @brief Get the smallest number index in stack
 * 
 * @param stack 
 * @return t_move 
 */
t_move	get_smallest(t_stack *stack)
{
	int		i;
	t_move	smallest;

	i = 0;
	smallest.n = INT_MAX;
	smallest.index = 0;
	while (i <= stack->top)
	{
		if (stack->data[i] < smallest.n)
		{
			smallest.n = stack->data[i];
			smallest.index = i;
		}
		i++;
	}
	return (smallest);
}
