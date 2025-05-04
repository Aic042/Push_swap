/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:21:55 by root              #+#    #+#             */
/*   Updated: 2025/05/04 09:37:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int index_of(int value, int *array, int size)
{
    int i = 0;
    while (i < size)
    {
        if (array[i] == value)
            return (i);
        i++;
    }
    return (-1);
}

void insertion_sort_array(int *array, int size)
{
    int i = 1;
    int j, key;
    while (i < size)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
        i++;
    }
}

void stack_starter(t_stack *stack_a, t_stack *stack_b, int *num_array, int count)
{
    int i;
    t_node *tmp;

    stack_a->head = NULL;
    stack_a->size = 0;
    stack_b->head = NULL;
    stack_b->size = 0;

    i = count - 1;
    while (i >= 0)
    {
        stack_head_placer(stack_a, 0, num_array[i]);
        i--;
    }

    int *sorted_array = malloc(sizeof(int) * count);
    if (!sorted_array)
    {
        ft_printf("Error: Memory allocation failed\n");
        exit(1);
    }
    i = 0;
    while (i < count)
    {
        sorted_array[i] = num_array[i];
        i++;
    }
    insertion_sort_array(sorted_array, count);

    tmp = stack_a->head;
    while (tmp)
    {
        tmp->s_index = index_of(tmp->value, sorted_array, count);
        tmp = tmp->next;
    }

    free(sorted_array);
}

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    int     *num_array;
    int     count;

    // Check for insufficient arguments
    if (argc < 2)
        return (0);

    // Parse arguments into num_array and count
    if (!parse_args(argc, argv, &num_array, &count))
    {
        ft_printf("Error\n");
        return (1);
    }

    // Initialize stacks and populate stack_a
    stack_starter(&stack_a, &stack_b, num_array, count);

    // Sort if stack_a is not already sorted
    if (!check_sorted(&stack_a))
        sort(&stack_a, &stack_b, num_array, count);

    // Free allocated memory
    free(num_array);
    stack_freer(&stack_a);
    stack_freer(&stack_b);

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
