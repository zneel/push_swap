#include "push_swap.h"

/**
 * @brief 
 * Swap a
 * Swap the first 2 elements at the top of stack a
 * Do nothing if there is only one or no elements.
 * @param stack_a 
 */
void	sa(t_stack *stack_a, int print)
{
	int	top;
	int	tmp;

	top = stack_a->top;
	if (stack_a->top > 1)
	{
		tmp = stack_a->data[top];
		stack_a->data[top] = stack_a->data[top - 1];
		stack_a->data[top - 1] = tmp;
        if (print)
		    ft_putendl_fd("sa", 1);
	}
}

/**
 * @brief 
 * Swap b
 * Swap the first 2 elements at the top of stack b
 * Do nothing if there is only one or no elements.
 * @param stack_b 
 */
void	sb(t_stack *stack_b, int print)
{
	int	top;
	int	tmp;

	top = stack_b->top;
	if (stack_b->top > 1)
	{
		tmp = stack_b->data[top];
		stack_b->data[top] = stack_b->data[top - 1];
		stack_b->data[top - 1] = tmp;
        if (print)
		    ft_putendl_fd("sb", 1);
	}
}

/**
 * @brief 
 * swap a and b at the same time
 * @param stack_a 
 * @param stack_b 
 */
void	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top > 1 && stack_b->top > 1)
	{
		sa(stack_a, 0);
		sb(stack_b, 0 );
		ft_putendl_fd("ss", 1);
	}
}

/**
 * @brief 
 * Push a
 * Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 * @param stack_b 
 * @param stack_a 
 */
void	pa(t_stack *stack_b, t_stack *stack_a)
{
	int	b_top;
	int	a_top;
	int	element;

	b_top = stack_b->top;
	a_top = stack_a->top;
	if (stack_b->top > 0)
	{
		element = stack_b->data[b_top];
		stack_a->data[++a_top] = element;
		stack_b->top--;
		stack_a->top++;
		ft_putendl_fd("pa", 1);
	}
}

/**
 * @brief 
 * Push b
 * Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 * @param stack_a 
 * @param stack_b 
 */
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	a_top;
	int	b_top;
	int	element;

	a_top = stack_a->top;
	b_top = stack_b->top;
	if (stack_a->top > 0)
	{
		element = stack_a->data[a_top];
		stack_b->data[++b_top] = element;
		stack_a->top--;
		stack_b->top++;
		ft_putendl_fd("pb", 1);
	}
}

/**
 * @brief 
 * rotate a
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 * @param stack_a 
 */
void	ra(t_stack *stack_a, int print)
{
	int	i;
	int	first;

	if (stack_a->top <= 0)
		return ;
	i = 0;
	first = stack_a->data[0];
	while (i++ < stack_a->top - 1)
		stack_a->data[i] = stack_a->data[i + 1];
	stack_a->data[stack_a->top - 1] = first;
    if (print)
	    ft_putendl_fd("ra", 1);
}

/**
 * @brief 
 * rotate b
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 * @param stack_b 
 */
void	rb(t_stack *stack_b, int print)
{
	int	i;
	int	first;

	if (stack_b->top <= 0)
		return ;
	i = 0;
	first = stack_b->data[0];
	while (i++ < stack_b->top - 1)
		stack_b->data[i] = stack_b->data[i + 1];
	stack_b->data[stack_b->top - 1] = first;
    if (print)
	    ft_putendl_fd("rb", 1);
}

/**
 * @brief 
 * ra and rb at the same time
 * @param stack_a 
 * @param stack_b 
 */
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_putendl_fd("rr", 1);
}

/**
 * @brief 
 * reverse rotate a
 * Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * @param stack_a 
 */
void	rra(t_stack *stack_a, int print)
{
	int	i;
	int	last;

	if (stack_a->top <= 0)
		return ;
	i = stack_a->top - 1;
	last = stack_a->data[stack_a->top - 1];
	while (i-- > 0)
		stack_a->data[i] = stack_a->data[i - 1];
	stack_a->data[0] = last;
    if (print)
	    ft_putendl_fd("rra", 1);
}

/**
 * @brief 
 * reverse rotate b
 * Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 * @param stack_b 
 */
void	rrb(t_stack *stack_b, int print)
{
	int	i;
	int	last;

	if (stack_b->top <= 0)
		return ;
	i = stack_b->top - 1;
	last = stack_b->data[stack_b->top - 1];
	while (i-- > 0)
		stack_b->data[i] = stack_b->data[i - 1];
	stack_b->data[0] = last;
    if (print)
    	ft_putendl_fd("rrb", 1);
}

/**
 * @brief 
 * rra and rrb at the same time.
 * @param stack_a 
 * @param stack_b
 */
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a, 0);
    rrb(stack_b, 0);
    ft_putendl_fd("rrr", 1);
}
