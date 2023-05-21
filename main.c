/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:10:52 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/21 20:07:43 by ebouvier         ###   ########.fr       */
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

int	find_index(int *arr, int size, int value)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (arr[index] == value)
			return (index);
		index++;
	}
	return (-1);
}

void	normalize(int *arr, int size)
{
	int	*sorted;
	int	index;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return ;
	ft_memcpy(sorted, arr, size * sizeof(int));
	quick_sort(sorted, 0, size - 1);
	index = 0;
	while (index < size)
	{
		arr[index] = find_index(sorted, size, arr[index]);
		index++;
	}
	free(sorted);
}
int	sorted(int a, int b)
{
	if (a < b)
		return (1);
	else if (a > b)
		return (-1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	int			*parsed;
	t_push_swap	instance;

	instance.output = NULL;
	if (ac == 1)
		return (0);
	if (!check_input(ac, av))
		return (ft_putstr_fd("Error\n", 2), 0);
	parsed = parse(ac, av);
	if (!parsed)
		return (ft_putstr_fd("Error\n", 2), 0);
	if (has_duplicates(parsed, ac - 1))
		return (free(parsed), ft_putstr_fd("Error\n", 2), 0);
	if (is_sorted(parsed, ac - 1, sorted))
		return (free(parsed), 0);
	normalize(parsed, ac - 1);
	if (!init_datastructures(parsed, ac - 1, &instance))
		return (free_and_exit(parsed, &instance));
	solve(&instance);
	ft_lstprint_str(instance.output);
	ft_lstclear(&instance.output, free);
	free_and_exit(parsed, &instance);
	return (0);
}
