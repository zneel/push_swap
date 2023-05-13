/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:10:52 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/13 23:18:32 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "push_swap.h"

int	init_datastructures(int *arr, int size, t_push_swap *instance)
{
	instance->stack_a = malloc(sizeof(t_stack));
	if (!instance->stack_a)
		return (0);
	instance->stack_a->data = malloc(sizeof(int) * (size));
	if (!instance->stack_a->data)
		return (0);
	instance->stack_a->top = size;
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

void print_stack(t_stack *stack)
{
	int i;

	i = stack->top - 1;
	printf("stack->top=%d\n", stack->top);
	printf("stack->size=%d\n", stack->size);
	while (i >= 0)
		printf("%d\n", stack->data[i--]);
	printf("-------------------------------------------\n");
}

int	main(int ac, char **av)
{
	int			*input;
	t_push_swap	instance;

	if (!check_input(ac, av))
		return (ft_putstr_fd("Error\n", 1), 0);
	input = parse(ac, av);
	if (!init_datastructures(input, ac - 1, &instance))
	{
		free(input);
		return (0);
	}
	printf("stack a\n");
	print_stack(instance.stack_a);
	printf("stack b\n");
	print_stack(instance.stack_b);

	sa(instance.stack_a,1);
	printf("stack a\n");
	print_stack(instance.stack_a);
	printf("stack b\n");
	print_stack(instance.stack_b);

	free(input);
	free(instance.stack_a->data);
	free(instance.stack_a);
	free(instance.stack_b->data);
	free(instance.stack_b);
	return (0);
}
