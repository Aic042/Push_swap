/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:22:21 by aingunza          #+#    #+#             */
/*   Updated: 2025/04/16 10:33:38 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa");
}

void	pb(t_stack_node **a, t_stack_node **b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb");
}

void argscheckers(int argc, char **argv)
{
    int i;
    int j;

	i = 1;
    if (argc == 1)
    {
        exit(1);
    }
    while (i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            if (!isdigit(argv[i][j]))
            {
                exit(1); 
            }
            j++;
        }
        i++;
    }
}

// int main(int argc, char **argv)
// {
// 	argscheckers(argc, argv);
// 	printf("All arguments are valid numbers!\n");

// 	return 0;
// }
