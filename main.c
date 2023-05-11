/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:10:52 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/11 23:53:05 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_input(int ac, char **av)
{
	int	i;
	int j;

	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}		
		i++;
	}
	return (1);
}

t_list	*parse_to_list(int ac, char **av)
{
	int		i;
	t_list	*head;
	t_list	*new;
	int		*val;

    i = 1;
    head = NULL;
    new = NULL;
    val = NULL;
	while (i < ac)
	{
		val = malloc(sizeof(int));
		if (!val)
			return (ft_lstclear(&head, free), NULL);
		*val = ft_atoi(av[i]);
		new = ft_lstnew(val);
        if (!new)
            return (ft_lstclear(&head, free), NULL);
		ft_lstadd_back(&head, new);
		i++;
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_list *stack;

	if (!check_input(ac, av))
		return (ft_putstr_fd("Error\n", 1), 0);
	stack = parse_to_list(ac, av);
	ft_lstprint_int(stack);
	ft_lstclear(&stack, free);
	return (0);
}