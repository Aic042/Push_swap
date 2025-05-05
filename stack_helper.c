/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:03:56 by aingunza          #+#    #+#             */
/*   Updated: 2025/05/05 12:27:34 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_head_placer(t_stack *stack, int index, int value)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
	{
		exit(1);
	}
	tmp->value = value;
	tmp->s_index = index;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->size++;
}
// Function push_stack(stack, index, data):
//     Allocate memory for a new node (tmp)
//     If memory allocation fails:
//         Return
//     Set tmp's data to data
//     Set tmp's index to index
//     Set tmp's next to the current head of the stack
//     Update the stack's head to point to tmp
//     Increment the stack's size

int	stack_head_taker(t_stack *stack)
{
	t_node	*top;
	int		value;

	if (!stack->head)
	{
		exit(1);
	}
	top = stack->head;
	value = top->value;
	stack->head = top->next;
	free(top);
	stack->size--;
	return (value);
}
/*

Function popping_a_stack(stack):
	If the stack's head is NULL (stack is empty):
		Exit the program with an error
	Set top to the current head of the stack
	Store top's data in a variable data
	Update the stack's head to the next node
	Free the memory allocated for top
	Decrement the stack's size
	Return the stored data
*/
