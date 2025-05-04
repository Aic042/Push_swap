/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:28:04 by root              #+#    #+#             */
/*   Updated: 2025/05/03 13:56:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In stackers.c
void	s_insertion_sort(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	min_index;
	int	iter;
	int	n;

	iter = 0;
	n = length;
	while (iter++ < n - 3)
	{
		min_index = get_min(stack_a);
		if (counter(stack_a->head, min_index) <= n - min_index - \
			counter(stack_a->head, min_index))
			while (stack_a->head->s_index != min_index)
				rotate(stack_a, 'a', true);
		else
			while (stack_a->head->s_index != min_index)
				reverse_rotate(stack_a, 'a', true);
		if (check_sorted(stack_a) && stack_b->size == 0)
			return ;
		push(stack_b, stack_a, 'b', true);
		length--;
	}
	simple_sorter(stack_a, length);
	iter = 0;
	while (iter++ < n - 3)
		push(stack_a, stack_b, 'a', true);
}

int	get_min(t_stack *stack)
{
	t_node *current;
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

int	check_sorted(t_stack *stack)
{
	t_node	*tmp;

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


void	stack_freer(t_stack *stack)
{
	while (stack)
		stack_head_taker(stack);
}
