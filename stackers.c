/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:13:10 by root              #+#    #+#             */
/*   Updated: 2025/05/15 13:48:44 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rot_sort(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->head->value;
	b = stack->head->next->value;
	c = stack->head->next->next->value;
	if (a < b && b < c)
		return (1);
	else if (b < c && a > c)
		return (1);
	else if (c < a && a < b)
		return (1);
	return (0);
}
// Checks if three numbers in the stack can be sorted with just one rotation.
// Returns 1 if a rotation works, 0 if more steps are needed.

void	simple_sorter(t_stack *stack, int len)
{
	int	min_index;
	int	i;

	if (check_sorted(stack))
		return ;
	min_index = get_min(stack);
	i = counter(stack->head, min_index);
	if (check_rot_sort(stack))
	{
		if (i < len - i)
			rotate(stack, 'a', 1);
		else
			reverse_rotate(stack, 'a', 1);
	}
	else
	{
		swap(stack, 'a', 1);
		if (check_sorted(stack))
			return ;
		if (i < len - i)
			rotate(stack, 'a', 1);
		else
			reverse_rotate(stack, 'a', 1);
	}
}
// Sorts a stack of three numbers using the fewest swaps or rotations possible.
// Stops when the stack is sorted in ascending order.

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
		if (counter(stack_a->head, min_index) <= stack_a->size / 2)
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
// Sorts 4 to 7 numbers by moving the smallest to stack_b, sorting the rest,
// then moving back. Uses rotations to save moves and keep the stack ordered.

//finally stack_len of stack_a divided by 14 is the solution
void	sort1(t_stack *stack_a, t_stack *stack_b) //k_sort1
{
	int	i;
	int	size;

	i = 0;
	size = stack_len(stack_a) / 12;
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
			rotate(stack_a, 'a', 1);
	}
}
// Groups numbers by their indices and moves them to stack_b for large stacks.
// Prepares stack_b for final sorting with minimal operations.

void	sorter2(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	rb_count;
	int	rrb_count;

	while (len - 1 >= 0)
	{
		rb_count = counter(stack_b->head, len - 1);
		rrb_count = len - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->s_index != len - 1)
				rotate(stack_b, 'b', 1);
			push(stack_a, stack_b, 'a', 1);
			len--;
		}
		else
		{
			while (stack_b->head->s_index != len - 1)
				reverse_rotate(stack_b, 'b', 1);
			push(stack_a, stack_b, 'a', 1);
			len--;
		}
	}
}
// Moves numbers from stack_b back to stack_a in the right order, starting 
// with the largest. Picks the fastest rotation to sort big stacks efficiently.