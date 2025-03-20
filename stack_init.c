/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:52:48 by root              #+#    #+#             */
/*   Updated: 2025/03/20 09:39:13 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void append_none(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;
	
	if (!stack)
		return;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long n;
	long i;
	
	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		append_none(a, (int)n);
		i++;
	}
}
