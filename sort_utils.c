/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:28:04 by root              #+#    #+#             */
/*   Updated: 2025/05/08 13:33:50 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In stackers.c

int	get_min(t_stack *stack)
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
	while (stack->head)
		stack_head_taker(stack);
}

void	sort(t_stack *stack_a, t_stack *stack_b, int *num_str, int len)
{
	if (check_sorted(stack_a))
	{
		free(num_str);
		stack_freer(stack_a);
	}
	else if (len == 2)
	{
		swap(stack_a, 'a', 1);
	}
	else if (len == 3)
	{
		simple_sorter(stack_a, len);
	}
	else if (len <= 7)
		s_insertion_sort(stack_a, stack_b, len);
	else if (len > 7)
	{
		sort1(stack_a, stack_b);
		sorter2(stack_a, stack_b, len);
	}
	else
		write(2, "Error\n", 6);
}
