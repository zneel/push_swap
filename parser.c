/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:13:21 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/21 20:18:18 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '0' && str[i + 1] != '\0')
		return (0);
	if (str[i] == 0)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_input(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (ft_strlen(av[i]) == 0)
			return (0);
		while (av[i][j])
		{
			if (!is_valid_int(av[i]))
				return (0);
			if (ft_strlen(av[i]) > 11)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	has_duplicates(int *input, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (input[i] == input[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	number_too_big(int *input, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (input[i] > INT_MAX || input[i] < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	*parse(int ac, char **av)
{
	int			i;
	long long	temp;
	int			*res;

	res = malloc(sizeof(int) * (ac - 1));
	if (!res)
		return (0);
	i = 1;
	while (i < ac)
	{
		temp = ft_atoll(av[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (free(res), NULL);
		res[ac - i - 1] = (int)temp;
		i++;
	}
	return (res);
}
