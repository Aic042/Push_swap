/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:15:07 by root              #+#    #+#             */
/*   Updated: 2025/05/12 10:27:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sort_data	allocate_and_copy(int *arr, int count)
{
	t_sort_data	data;
	int			i;

	data.sorted = malloc(sizeof(int) * count);
	data.indices = malloc(sizeof(int) * count);
	if (!data.sorted || !data.indices)
		exit(1);
	i = -1;
	while (++i < count)
		data.sorted[i] = arr[i];
	return (data);
}

void	sort_and_index(int *arr, t_sort_data *data, int count)
{
	int	i;
	int	j;

	i = -1;
	while (++i < count - 1)
	{
		j = -1;
		while (++j < count - i - 1)
			if (data->sorted[j] > data->sorted[j + 1])
			{
				int tmp = data->sorted[j];
				data->sorted[j] = data->sorted[j + 1];
				data->sorted[j + 1] = tmp;
			}
	}
	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count)
			if (arr[i] == data->sorted[j])
				data->indices[i] = j;
	}
}

static void	init_stacks(t_stack *a, int *arr, int count)
{
	t_sort_data	data;
	int			i;

	data = allocate_and_copy(arr, count);
	sort_and_index(arr, &data, count);
	i = count;
	while (--i >= 0)
		stack_head_placer(a, data.indices[i], arr[i]);
	free(data.sorted);
	free(data.indices);
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
	return (1);
}

int main(int argc, char **argv)
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

// static void init_stacks(t_stack *a, int *arr, int count)
// {
// 	int	i;
// 	int	*sorted;
// 	int	*indices;
// 	int j;
// 	sorted = malloc(sizeof(int) * count);
// 	indices = malloc(sizeof(int) * count);
// 	if (!sorted || !indices)
// 		exit(1);
// 	// for (i = 0; i < count; i++)
// 	// 	sorted[i] = arr[i];
// 	i = 0;
// 	while(i < count)
// 	{
// 		i++;
// 		sorted[i] = arr[i];
// 	}
// 	// for (i = 0; i < count - 1; i++)
// 	// 	for (int j = 0; j < count - i - 1; j++)
// 	// 		if (sorted[j] > sorted[j + 1])
// 	// 		{
// 	// 			int tmp = sorted[j];
// 	// 			sorted[j] = sorted[j + 1];
// 	// 			sorted[j + 1] = tmp;
// 	// 		}
// 	i = 0;
// 	j = 0;
// 	while (i < count - 1)
// 	{
// 		i++;
// 		while (j < count - i - 1)
// 		{
// 			j++;
// 			if (sorted[j] > sorted[j + 1])
// 			{
// 				int tmp = sorted[j];
// 				sorted[j] = sorted[j + 1];
// 				sorted[j + 1] = tmp;
// 			}
// 		}
		
// 	}
	
// 	// for (i = 0; i < count; i++)
// 	// 	for (int j = 0; j < count; j++)
// 	// 		if (arr[i] == sorted[j])
// 	// 			indices[i] = j;
				
// 	i = 0;
// 	j = 0;
// 	while (i < count)
// 	{
// 		i++;
// 		while (j < count)
// 		{
// 			j++;
// 			if (arr[i] == sorted[j])
// 				indices[i] = j;			
// 		}
		
// 	}
// 	i = count;
// 	while (--i >= 0)
// 		stack_head_placer(a, indices[i], arr[i]);
// 	free(sorted);
// 	free(indices);
// }