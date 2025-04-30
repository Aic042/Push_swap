/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:28:04 by root              #+#    #+#             */
/*   Updated: 2025/04/29 19:59:57 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_node *stack)
{
	t_node	*current;
	int		min_index;
	
	current = stack->head;
	min_index = current->s_index;
	while (current->next)
	{
		current = current->next;
		if (current->s_index < min_index)
			min_index = current->s_index;
	}
	return (min_index);
}
int	counter(t_node *stack, int i)
{
	int		count;

	count = 0;
	while (stack && stack->s_index != i)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int		check_sorted(t_stack *stack)
{
	t_node *tmp;
	
	tmp = stack->head;
	if (!tmp)
		return (1);
		while (tmp->next)
		{
			if (tmp->value > tmp->next->value)
				return (0);
			tmp = tmp->next;
		}
	return (1);
}

int	pop_stack(t_stack *stack)
{
	t_node	*top;
	int		data;

	if (!stack->head)
		exit(1);
	top = stack->head;
	data = top->value;
	stack->head = top->next;
	free(top);
	top = NULL;
	stack->size--;
	return (data);
}
void stack_freer(t_stack *stack)
{
	while(stack)
		pop_stack(stack);
}
