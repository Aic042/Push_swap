#include "push_swap.h"

static void set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;
	
	while(a)
	{
		best_match_index = __LONG_MIN__;
		current_b = b;
		while (current_b)
		{
			if(current_b->nbr > b->nbr && current_b->nbr < best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if(best_match_index == __LONG_MIN__)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;		
	}
}