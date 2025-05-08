/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:21:55 by root              #+#    #+#             */
/*   Updated: 2025/05/08 16:04:03 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void init_stacks(t_stack *a, t_stack *b, int *arr, int count)
{
	int	i;
	int	*sorted;
	int	*indices;

	a->head = NULL;
	a->size = 0;
	b->head = NULL;
	b->size = 0;

	sorted = malloc(sizeof(int) * count);
	indices = malloc(sizeof(int) * count);
	if (!sorted || !indices)
		exit(1);
	for (i = 0; i < count; i++)
		sorted[i] = arr[i];
	for (i = 0; i < count - 1; i++)
		for (int j = 0; j < count - i - 1; j++)
			if (sorted[j] > sorted[j + 1])
			{
				int tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
			}
	for (i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
			if (arr[i] == sorted[j])
				indices[i] = j;
	i = count;
	while (--i >= 0)
		stack_head_placer(a, indices[i], arr[i]);
	free(sorted);
	free(indices);
}
//AI made this function. Still trying to find an explanation for why my 4-6 line function has been turned into this monstrosity.

int last_parse_args(char **argv)
{
	if (ft_strlen(argv[1]) == 0)
	{
		print_error();
		return (0);
	}
	else
		return (1);
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
		return (1);
	if (!last_parse_args(argv))
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

// % ./push_swap "-3 1   '-6'  "

// ./push_swap +-000009 -1
// Error
// sa





// % valgrind --leak-check=full  ./push_swap 2343 5 23 65 5
// ==1552113== Memcheck, a memory error detector
// ==1552113== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==1552113== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
// ==1552113== Command: ./push_swap 2343 5 23 65 5
// ==1552113== 
// Error
// ==1552113== 
// ==1552113== HEAP SUMMARY:
// ==1552113==     in use at exit: 20 bytes in 1 blocks
// ==1552113==   total heap usage: 18 allocs, 17 frees, 189 bytes allocated
// ==1552113== 
// ==1552113== 20 bytes in 1 blocks are definitely lost in loss record 1 of 1
// ==1552113==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
// ==1552113==    by 0x40150E: parse_args (pars_utils.c:89)
// ==1552113==    by 0x401D5B: main (push_swap.c:73)
// ==1552113== 
// ==1552113== LEAK SUMMARY:
// ==1552113==    definitely lost: 20 bytes in 1 blocks
// ==1552113==    indirectly lost: 0 bytes in 0 blocks
// ==1552113==      possibly lost: 0 bytes in 0 blocks
// ==1552113==    still reachable: 0 bytes in 0 blocks
// ==1552113==         suppressed: 0 bytes in 0 blocks
// ==1552113== 
// ==1552113== For lists of detected and suppressed errors, rerun with: -s
// ==1552113== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
