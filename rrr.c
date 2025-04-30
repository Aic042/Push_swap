/* ************************************************************************** */

#include "push_swap.h"
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:13:04 by aingunza          #+#    #+#             */
/*   Updated: 2025/01/30 11:13:05 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack) //Define a function that rotates the stack's top node to the bottom of the stack
{
	t_stack_node	*last_node; //To store a pointer to the last node of a stack

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last_node = find_last(*stack); 
	last_node->next = *stack; //Assign to the last node, its `next` attribute as the top node, effectively setting the current top node as the last node
	*stack = (*stack)->next; //Assign to the pointer of the top node, the node after it (second from the top)
	(*stack)->prev = NULL; //Complete setting the current top node by detaching it from its previous top node
	last_node->next->prev = last_node; //Reconnect the second node's prev pointer to point	to what was previously the last node in the stack
	last_node->next->next = NULL; //Assign to the `next` attribute of the current last node, `NULL` effectively setting it as the current last node, and properly null terminating the stack
}	

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}
void rra(t_stack_node **a, bool print)
{
    t_stack_node *last;
    t_stack_node *second_last;

    if (!*a || !(*a)->next)
        return;
    last = find_last(*a);
    second_last = last->prev;
    last->next = *a;
    last->prev = NULL;
    second_last->next = NULL;
    (*a)->prev = last;
    *a = last;
    if (!print)
        ft_printf("rra\n");
}

void rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    rra(a, true); // Pass true to suppress individual prints
    rrb(b, true);
    if (!print)
        ft_printf("rrr\n");
}

void rrb(t_stack_node **b, bool print)
{
    t_stack_node *last;
    t_stack_node *second_last;

    if (!*b || !(*b)->next)
        return;
    last = find_last(*b);
    second_last = last->prev;
    last->next = *b;
    last->prev = NULL;
    second_last->next = NULL;
    (*b)->prev = last;
    *b = last;
    if (!print)
        ft_printf("rrb\n");
}