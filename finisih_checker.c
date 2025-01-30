/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finisih_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:11:08 by aingunza          #+#    #+#             */
/*   Updated: 2025/01/30 15:52:58 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void argc_checker(int argc)
{
    if(argc < 1)
        ft_error;
}

void finished_stacking(t_push_utils *push_utils)
{
    if(signal == on)
    {
        exit(EXIT_SUCCESS);
    }
}

void ft_error()
{
    ft_printf(Err_message);
}