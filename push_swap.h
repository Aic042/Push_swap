/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:10:06 by aingunza          #+#    #+#             */
/*   Updated: 2025/03/14 20:55:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define Err_message "Nah, this thing ain't working\n"
#define Err_type_no_int "Check those args please. You did? Okay, check again.\n"
#define Err_type_long_num "There has to be some big ahh number cause this thing ain't working\n"
#define Err_type_duplicate "Duplicate numbers. I repeat, duplicate numbers. 🦜\n"

typedef struct s_stack_node
{
    int         nbr;
    int         index;
    int         push_cost;
    bool        above_median;
    bool        cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
} t_stack_node;

int				error_syntax(char *str_n); 
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);

//***Stack initiation
void			init_stack_a(t_stack_node **a, char **argv); //Initiate stack `a` before processing
char			**split(char *s, char c); //To handle input of numbers as a string argument, e.g. enclosed in " "

//***Nodes initiation
void			init_nodes_a(t_stack_node *a, t_stack_node *b); //To prep all nodes for pushing `a` to `b`
void			init_nodes_b(t_stack_node *a, t_stack_node *b); //To prep all nodes for pushing `b` back to `a`
void			current_index(t_stack_node *stack); //Set the node's current index
void			set_cheapest(t_stack_node *stack); //Set the stack's cheapest node
t_stack_node	*get_cheapest(t_stack_node *stack); //Get the cheapest node of a stack
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c); //Prep the required nodes on top for pushing

//***Stack utils
int				stack_len(t_stack_node *stack); //Calculate the length of a stack
t_stack_node	*find_last(t_stack_node *stack); //Find the last node of a stack
bool			stack_sorted(t_stack_node *stack); //To check whether a stack is sorted
t_stack_node	*find_min(t_stack_node *stack); //Find the smallest number
t_stack_node	*find_max(t_stack_node *stack); //Find the biggest number

//***Commands
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);

//***Algorithm
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b); //Turk algorithm

#endif