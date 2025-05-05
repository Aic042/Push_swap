/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:21:55 by root              #+#    #+#             */
/*   Updated: 2025/05/05 15:02:25 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void init_stacks(t_stack *a, t_stack *b, int *arr, int count)
{
	int i;
	int *sorted;
	int *indices;

	a->head = NULL;
	a->size = 0;
	b->head = NULL;
	b->size = 0;

	// Create a sorted copy of arr to assign indices
	sorted = malloc(sizeof(int) * count);
	indices = malloc(sizeof(int) * count);
	if (!sorted || !indices)
		exit(1);
	for (i = 0; i < count; i++)
		sorted[i] = arr[i];
	// Simple bubble sort for sorted array
	for (i = 0; i < count - 1; i++)
		for (int j = 0; j < count - i - 1; j++)
			if (sorted[j] > sorted[j + 1])
			{
				int tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
			}
	// Assign indices based on sorted positions
	for (i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
			if (arr[i] == sorted[j])
				indices[i] = j;
	// Push to stack with correct indices
	i = count;
	while (--i >= 0)
		stack_head_placer(a, indices[i], arr[i]);
	free(sorted);
	free(indices);
}
//AI made this function. Still trying to find an explanation for why my 4-6 line function has been turned into this monstrosity.

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*nums;
	int		count;

	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &nums, &count))
		return (1);
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
