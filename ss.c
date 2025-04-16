/* ************************************************************************** */

#include "push_swap.h"
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:13:24 by aingunza          #+#    #+#             */
/*   Updated: 2025/01/30 11:13:25 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack_node **a, bool print)
{
    t_stack_node *first;
    t_stack_node *second;

    if (!*a || !(*a)->next)
        return;
    first = *a;
    second = (*a)->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->next = first;
    second->prev = NULL;
    first->prev = second;
    *a = second;
    if (!print)
        ft_printf("sa\n");
}