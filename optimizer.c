/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:26:11 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/21 14:23:42 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lists.h"

t_list	*optimize_instruction(t_list *current, char *new_instruction)
{
	t_list	*temp;

	free(current->content);
	current->content = ft_strdup(new_instruction);
	temp = current->next;
	current->next = temp->next;
	free(temp->content);
	free(temp);
	return (current);
}

int	optimize_rr(t_list *current)
{
	if (current && current->next && ft_strncmp(current->content, "ra", 2) == 0
		&& ft_strncmp(current->next->content, "rb", 2) == 0)
	{
		optimize_instruction(current, "rr\n");
		return (1);
	}
	return (0);
}

int	optimize_rrr(t_list *current)
{
	if (current && current->next && ft_strncmp(current->content, "rra", 3) == 0
		&& ft_strncmp(current->next->content, "rrb", 3) == 0)
	{
		optimize_instruction(current, "rrr\n");
		return (1);
	}
	return (0);
}

int	optimize_ss(t_list *current)
{
	if (current && current->next && ft_strncmp(current->content, "sa", 2) == 0
		&& ft_strncmp(current->next->content, "sb", 2) == 0)
	{
		optimize_instruction(current, "ss\n");
		return (1);
	}
	return (0);
}

void	optimize_instructions(t_list *lst)
{
	t_list	*current;
	t_list	*prev;

	current = lst;
	prev = NULL;
	while (current && current->next)
	{
		if (optimize_rr(current) || optimize_rrr(current)
			|| optimize_ss(current))
		{
			if (prev)
				current = prev;
			else
				current = lst;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}
