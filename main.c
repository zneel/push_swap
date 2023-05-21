/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:10:52 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/21 13:43:51 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_datastructures(int *arr, int size, t_push_swap *instance)
{
	instance->stack_a = malloc(sizeof(t_stack));
	if (!instance->stack_a)
		return (0);
	instance->stack_a->data = malloc(sizeof(int) * (size));
	if (!instance->stack_a->data)
		return (0);
	instance->stack_a->top = size - 1;
	instance->stack_a->size = size;
	ft_memcpy(instance->stack_a->data, arr, size * sizeof(int));
	instance->stack_b = malloc(sizeof(t_stack));
	if (!instance->stack_b)
		return (0);
	instance->stack_b->data = malloc(sizeof(int) * (size));
	if (!instance->stack_b->data)
		return (0);
	instance->stack_b->top = -1;
	instance->stack_b->size = size;
	return (1);
}

int	find_index(int *arr, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	normalize(int *arr, int n)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * n);
	if (!sorted)
		return ;
	ft_memcpy(sorted, arr, n * sizeof(int));
	quick_sort(sorted, 0, n - 1);
	i = 0;
	while (i < n)
	{
		arr[i] = find_index(sorted, n, arr[i]);
		i++;
	}
	free(sorted);
}

int	sorted(int a, int b)
{
	return (b - a);
}

int	main(int ac, char **av)
{
	int			*input;
	t_push_swap	instance;

	if (ac == 1)
		return (0);
	if (!check_input(ac, av))
		return (ft_putstr_fd("Error\n", 1), 0);
	input = parse(ac, av);
	if (is_sorted(input, ac - 1, sorted))
		return (free(input), 0);
	normalize(input, ac - 1);
	instance.output = NULL;
	if (!init_datastructures(input, ac - 1, &instance))
		return (free_and_exit(input, &instance));
	solve(&instance);
	optimize_instructions(instance.output);
	ft_lstprint_str(instance.output);
	ft_lstclear(&instance.output, free);
	free_and_exit(input, &instance);
	return (0);
}
