/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:58:37 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/21 20:59:13 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	allocate_stack(t_stack **stack, int *arr, int size)
{
	*stack = malloc(sizeof(t_stack));
	if (!*stack)
		return (0);
	(*stack)->data = malloc(sizeof(int) * size);
	if (!(*stack)->data)
		return (0);
	(*stack)->top = size - 1;
	(*stack)->size = size;
	ft_memcpy((*stack)->data, arr, size * sizeof(int));
	return (1);
}

int	init_datastructures(int *arr, int size, t_push_swap *instance)
{
	if (!allocate_stack(&instance->stack_a, arr, size))
		return (0);
	instance->stack_a->top = size - 1;
	instance->stack_a->size = size;
	if (!allocate_stack(&instance->stack_b, arr, size))
		return (0);
	instance->stack_b->top = -1;
	instance->stack_b->size = size;
	return (1);
}
