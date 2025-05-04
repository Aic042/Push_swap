/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:07:15 by root              #+#    #+#             */
/*   Updated: 2025/05/03 14:14:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char x, bool b)
{
	t_node	*tmp;

if (!stack->head || !stack->head->next)
{
	ft_printf("Error\n");
	return;
}
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

	if (!stack1->head)
	{

		return;
	}
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

if (!stack->head || !stack->head->next)
{
	ft_printf("Error\n");
	return;
}
	tmp = stack->head;
	stack->head = tmp->next;
	last = stack->head;
	while (last->next)
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

if (!stack->head || !stack->head->next)
{
	ft_printf("Error\n");
	return;
}
	tmp = stack->head;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = stack->head;
	stack->head = last;
	if (b)
		ft_printf("rr%c\n", x);
}
