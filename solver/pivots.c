/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivots.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:16:51 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/21 12:17:18 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief Generate n numbers of pivots from min max
 * 
 * @param	stack
 * @return	*pivots 
 */
t_pivots	*get_pivots(t_stack *stack, int pivots_count)
{
	t_pivots	*pivots;
	int			step;
	int			i;

	i = 0;
	pivots = malloc(sizeof(t_pivots));
	if (!pivots)
		return (NULL);
	pivots->count = pivots_count;
	pivots->pivots = malloc(sizeof(t_pivot) * pivots->count);
	if (!pivots->pivots)
		return (free(pivots), NULL);
	step = stack->size / pivots->count;
	while (i < pivots->count)
	{
		if (i == 0)
			pivots->pivots[i].min = -1;
		else
			pivots->pivots[i].min = pivots->pivots[i - 1].max + 1;
		if (i == pivots->count - 1)
			pivots->pivots[i].max = stack->size;
		else
			pivots->pivots[i].max = (i + 1) * step;
		i++;
	}
	return (pivots);
}