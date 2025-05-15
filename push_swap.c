/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:15:07 by root              #+#    #+#             */
/*   Updated: 2025/05/15 13:20:05 by aingunza         ###   ########.fr       */
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
	i = 0;
	while (i < count)
	{
		data.sorted[i] = arr[i];
		i++;
	}
	return (data);
}
// Allocates memory for the sorted array and indices array, 
// copies the input array into the sorted array, and returns the 
// initialized data structure.

void	sort_and_index(int *arr, t_sort_data *data, int count)
{
	int	i;
	int	j;

	i = -1;
	while (++i < count - 1)
	{
		j = -1;
		while (++j < count - i - 1)
		{
			if (data->sorted[j] > data->sorted[j + 1])
			{
				data->srt_indx_tmp = data->sorted[j];
				data->sorted[j] = data->sorted[j + 1];
				data->sorted[j + 1] = data->srt_indx_tmp;
			}
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
// Sorts the array in ascending order using Bubble Sort and assigns indices 
// to the original array elements based on their positions in the sorted array.
//No me cabian i++ ni j++ por eso inicialize desde -1 para usar while(++i...)

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
// Initializes the stack a by sorting and indexing the input array, 
// then placing elements ito the stack in the correct order.

void	init_variables(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->head = NULL;
	stack_a->size = 0;
	stack_b->head = NULL;
	stack_b->size = 0;
}
//No explanation needed

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
	if (ft_strlen(argv[1]) == 0)
	{
		print_error();
		return (0);
	}
	init_variables(&a, &b);
	init_stacks(&a, nums, count);
	if (!check_sorted(&a))
		sort(&a, &b, nums, count);
	free(nums);
	stack_freer(&a);
	stack_freer(&b);
	return (0);
}
//Que es...? Count, la cantidad de input nums. Nums es el array de ints
//stack a y b... bueno, son stacks
//Parseo, etc, etc, etc...
//inicializar variables, luego stacks, mire arriba para mas explicación
//miramos si esta ya sorted, si lo esta de lujo! fin del programa.

// int	last_parse_args(char **argv)
// {
// 	if (ft_strlen(argv[1]) == 0)
// 	{
// 		print_error();
// 		return (0);
// 	}
// 	return (1);
// }