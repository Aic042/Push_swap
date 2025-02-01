/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:10:06 by aingunza          #+#    #+#             */
/*   Updated: 2025/02/01 17:56:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define Err_message "Nah, this thing ain't working\n"
#define Err_type_no_int "Check those args please. You did? Okay, check again.\n"
#define Err_type_long_num "There has to be some big ahh number cause this thing ain't working\n"
#define Err_type_duplicate "Duplicate numbers. I repeat, duplicate numbers. 🦜\n"

typedef struct s_stacknode
{
    int nbr;
    int index;
    int push_cost;
    int push_cost;
    bool    
};

typedef struct push_tils
{
    int     signal;
} t_push_utils

#endif