/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:07:15 by root              #+#    #+#             */
/*   Updated: 2025/05/05 11:19:35 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char x, bool b)
{
	t_node	*tmp;

	if (!stack->head || !stack->head->next)
	{
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
	int i;
	
	if (stack2->head == NULL)
	{
		return;
	}	
	i = stack2->head->s_index;
	stack_head_placer(stack1, i, stack_head_taker(stack2));
	if (b)
	{
		ft_printf("p%c\n", x);
	}
}

void	rotate(t_stack *stack, char x, bool b)
{
	t_node	*tmp;
	t_node	*last;

	if (!stack->head || !stack->head->next)
	{
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
