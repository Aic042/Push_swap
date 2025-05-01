/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:13:10 by root              #+#    #+#             */
/*   Updated: 2025/05/01 22:13:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void variable_initializer(t_stack *stack_a, t_stack *stack_b, int *num, int count)
{
	stack_a->head = NULL;
	stack_a->size = 0;
	stack_b->head = NULL;
	stack_b->size = 0;
}

void sort(t_stack *stack_a, t_stack *stack_b, int *num_str, int len)
{
	int i;
	int size;

	i = 0;
	size = (len / 10) * 14;
	while (stack_a->head)
	{
		if (stack_a->head->s_index <= i)
		{
			push(stack_b, stack_a, 'b', 1);
			rotate(stack_b, 'b', 1);
			i++;
		}
		else if (stack_a->head->s_index <= i + size)
		{
			push(stack_b, stack_a, 'b', 1);
			i++;
		}
		else
		{
			rotate(stack_a, 'a', 1);
		}
	}
	sorter2(stack_a, stack_b, len);
	stack_eraser(stack_b);
	stack_eraser(stack_a);
}

void	sort1(t_stack *stack_a, t_stack *stack_b, int len)
{
	int i;
	int size;
	
	i = 0;
	size = (len / 10) * 14;
	while (stack_a->head)
	{
		if (stack_a->head->s_index <= i)
		{
			push(stack_b, stack_a, 'b', 1);
			rotate(stack_b, 'b', 1);
			i++;
		}
		else if (stack_a->head->s_index <= i + size)
		{
			push(stack_b, stack_a, 'b', 1);
			i++;
		}
		else
		{
			rotate(stack_a, 'a', 1);
		}
	}
}

void	sorter2(t_stack *stack_a, t_stack *stack_b, int len)
{
	int rb;
	int rrb;
	int rrr;

	while (len - 1 > 0)
	{
		rb = counter(stack_b->head, stack_b->head->s_index);
		rrb = counter(stack_b->head, stack_b->head->s_index);
		rrr = counter(stack_a->head, stack_a->head->s_index);
		if (rb < rrb && rb < rrr)
			rotate(stack_b, 'b', 1);
		else if (rrb < rb && rrb < rrr)
			reverse_rotate(stack_b, 'b', 1);
		else
			reverse_rotate(stack_a, 'a', 1);
	len--;
	}
}
