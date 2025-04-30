/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:07:15 by root              #+#    #+#             */
/*   Updated: 2025/04/30 11:06:56 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char x, bool b)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->head->next == NULL)
		return (1);
	tmp = stack->head;
	stack->head = tmp->next;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
	if (b)
		ft_printf("s%c\n", x);
}

void	push(t_stack *stack1, t_stack *stack2, char x, bool b)
{
	t_node	*tmp;

	if (stack2->head == NULL)
		return (1);
	tmp = stack1->head;
	stack1->head = tmp->next;
	tmp->next = stack2->head;
	stack2->head = tmp;
	if (b)
		ft_printf("p%c\n", x);
}

void	rotate(t_stack *stack, char x, bool b)
{
	t_node	*tmp;
	t_node	*last;

	if (stack->head == NULL || stack->head->next == NULL)
		return (1);
	tmp = stack->head;
	stack->head = tmp->next;
	last = stack->head;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	if (b)
		ft_printf("r%c\n", x);
}

void	reverse_rotate(t_stack *stack, char x, bool b)
{
	t_node	*tmp;
	t_node	*last;

	if (stack->head == NULL || stack->head->next == NULL)
		return (1);
	tmp = stack->head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = stack->head;
	stack->head = last;
	if (b)
		ft_printf("rr%c\n", x);
}
