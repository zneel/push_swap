/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:25:11 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/21 14:24:33 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_and_exit(int *input, t_push_swap *instance)
{
	free(input);
	free(instance->stack_a->data);
	free(instance->stack_a);
	free(instance->stack_b->data);
	free(instance->stack_b);
	return (0);
}
