/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:46:29 by root              #+#    #+#             */
/*   Updated: 2025/03/20 09:39:13 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return(1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr);
			return (false);
		stack = stack->next;
	}
	return(true);	
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
