/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:46:29 by root              #+#    #+#             */
/*   Updated: 2025/04/25 12:14:47 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool 	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return(1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return(true);	
}

void free_stack(t_stack_node **stack)
{
    t_stack_node *tmp;

    if (!stack || !*stack)
        return;
    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}

t_stack_node *find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return(NULL);
	min = __LONG_MAX__;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return(min_node);
}
int	stack_len(t_stack_node *stack)
{
    int	len = 0;
    while (stack)
    {
        len++;
        stack = stack->next;
    }
    return (len);
}

t_stack_node *find_last(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

void free_errors(t_stack_node **a)
{
    free_stack(a);
    ft_printf(ERR_MESSAGE); // Or a specific error message
    exit(1);
}