/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:21:55 by root              #+#    #+#             */
/*   Updated: 2025/05/01 13:06:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int num = 0;
	int count = 0;
	variable_initializer(stack_a, stack_b, num, count);
	sort(stack_a, stack_b, num, count);
	check_sorted(stack_a);
	check_sorted(stack_b);
	return (0);
}

void	sort(t_stack *stack_a, t_stack *stack_b, int *num_str, int len)
{

}
