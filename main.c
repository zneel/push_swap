/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotbouvier <elliotbouvier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:10:52 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/13 17:37:28 by elliotbouvi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
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

int	*parse(int ac, char **av)
{
	int	i;
	int	*res;

	i = 0;
	res = malloc(sizeof(int) * (ac - 1));
	if (!res)
		return (0);
	while (i < ac - 1)
	{
		res[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (res);
}

void	print_arr(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
		printf("%d\n", arr[i++]);
}

int	main(int ac, char **av)
{
	int		*input;
	t_push_swap	ps;

	if (!check_input(ac, av))
		return (ft_putstr_fd("Error\n", 1), 0);
	input = parse(ac, av, &ps);
	print_arr(input, ac - 1);
	free(input);
	return (0);
}
