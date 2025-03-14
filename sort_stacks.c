/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:59:13 by root              #+#    #+#             */
/*   Updated: 2025/02/04 19:54:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	if(cheapest_node = ge)
	
}


void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int len_a;
	
	len_a = stack_len(*a);
	if(len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if(len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while(len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while(*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

static void set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;
	
	while(b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if(current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				b->target_node = find_min(a);
			}
			current_a = current_a->next;
		}
		if(best_match_index == __LONG_MAX__)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;		
	}
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}