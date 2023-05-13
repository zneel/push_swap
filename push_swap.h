/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliotbouvier <elliotbouvier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:09:32 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/13 18:10:43 by elliotbouvi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				*data;
	int				top;
	int				size;
}					t_stack;

typedef struct s_push_swap
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}					t_push_swap;

#endif