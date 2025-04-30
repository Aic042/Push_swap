/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:22:21 by aingunza          #+#    #+#             */
/*   Updated: 2025/04/27 19:46:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void pa(t_stack_node **a, t_stack_node **b, bool print)
{
    push(a, b);
    if (!print)
        ft_printf("pa\n");
}

void pb(t_stack_node **a, t_stack_node **b, bool print)
{
    push(b, a);
    if (!print)
        ft_printf("pb\n");
}

// int	main(int argc, char **argv)
// {
// 	argscheckers(argc, argv);
// 	printf("All arguments are valid numbers!\n");

// 	return 0;
// }
