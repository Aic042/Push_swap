/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:21:55 by root              #+#    #+#             */
/*   Updated: 2025/05/09 10:28:33 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void init_stacks(t_stack *a, int *arr, int count)
{
	int	i;
	int	*sorted;
	int	*indices;

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

void	init_variables(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->head = NULL;
	stack_a->size = 0;
	stack_b->head = NULL;
	stack_b->size = 0;
}

int	last_parse_args(char **argv)
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
	init_variables(&a, &b);
	init_stacks(&a, nums, count);
	if (!check_sorted(&a))
		sort(&a, &b, nums, count);
	free(nums);
	stack_freer(&a);
	stack_freer(&b);
	return (0);
}
