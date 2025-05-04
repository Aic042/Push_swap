/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:21:55 by root              #+#    #+#             */
/*   Updated: 2025/05/04 12:14:42 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(t_stack *a, t_stack *b, int *arr, int count)
{
	int	i;

	a->head = NULL;
	a->size = 0;
	b->head = NULL;
	b->size = 0;
	i = count;
	while (--i >= 0)
		stack_head_placer(a, 0, arr[i]);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*nums;
	int		count;

	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &nums, &count))
		return (ft_printf("Error\n"), 1);
	init_stacks(&a, &b, nums, count);
	if (!check_sorted(&a))
		sort(&a, &b, nums, count);
	free(nums);
	stack_freer(&a);
	stack_freer(&b);
	return (0);
}


// Prototipo V1.0
// int main(int argc, char **argv)
// {
// 	t_stack	stack_a;
// 	t_stack	stack_b;
// 	// int num = 0;
// 	int count = 0;
	
// 	parse_args(argc, argv);
// 	int *num_array = 0;
// 	variable_initializer(&stack_a, &stack_b, num_array, count);
// 	sort(&stack_a, &stack_b, num_array, count);
// 	check_sorted(&stack_a);
// 	// check_sorted(stack_b); Nevermind, we don't need to check stack_b
// 	return (0);
// }
