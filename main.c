/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:10:52 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/16 22:49:15 by ebouvier         ###   ########.fr       */
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

void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->top;
	printf("stack->top=%d\n", stack->top);
	printf("stack->size=%d\n", stack->size);
	while (i >= 0)
		printf("%d\n", stack->data[i--]);
	printf("-------------------------------------------\n");
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

int	main(int ac, char **av)
{
	int			*input;
	t_push_swap	instance;

	if (!check_input(ac, av))
		return (ft_putstr_fd("Error\n", 1), 0);
	input = parse(ac, av);
	normalize(input, ac - 1);
	if (!init_datastructures(input, ac - 1, &instance))
		return (free(input), 0);
	// printf("stack a\n");
	// print_stack(instance.stack_a);
	// printf("stack b\n");
	// print_stack(instance.stack_b);
	// sa(instance.stack_a,1);
	// pb(instance.stack_a, instance.stack_b);
	// pb(instance.stack_a, instance.stack_b);
	// pb(instance.stack_a, instance.stack_b);
	// 	printf("stack a\n");
	// print_stack(instance.stack_a);
	// printf("stack b\n");
	// print_stack(instance.stack_b);
	// rr(instance.stack_a, instance.stack_b);
	// printf("stack a\n");
	// print_stack(instance.stack_a);
	// printf("stack b\n");
	// print_stack(instance.stack_b);
	solve(&instance);
	free(input);
	free(instance.stack_a->data);
	free(instance.stack_a);
	free(instance.stack_b->data);
	free(instance.stack_b);
	instance.output = ft_lstreverse(instance.output);
	ft_lstprint_str(instance.output);
	ft_lstclear(&instance.output, free);
	return (0);
}
