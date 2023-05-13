/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:09:32 by ebouvier          #+#    #+#             */
/*   Updated: 2023/05/13 16:53:58 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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