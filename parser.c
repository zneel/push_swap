/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:13:21 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/13 23:27:11 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(int ac, char **av)
{
	int	i;
	int	j;

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

int *parse(int ac, char **av)
{
    int i;
    int *res;

    res = malloc(sizeof(int) * (ac - 1));
    if (!res)
        return (0);

    i = 1;
    while (i < ac)
    {
        res[ac - i - 1] = ft_atoi(av[i]);
        i++;
    }
    return (res);
}

void	print_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		printf("%d\n", arr[i++]);
}