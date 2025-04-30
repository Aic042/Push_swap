/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:11:08 by root              #+#    #+#             */
/*   Updated: 2025/04/30 15:17:55 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				s_index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

////////////////// PARSING //////////////////////
int		*arg_parse(int argc, char **argv, int length);
int		check_dups(int *num_array, int size);
void	free_split(char **split);
int		is_nbr(char *str);
int		parse_args(int argc, char **argv);
char	*join_args(int argc, char **argv);

/////////////////// STACK /////////////////////////

void	stack_starter(t_stack *stack_a, t_stack *stack_b, int *nb, int count);
void	stack_pusher(t_stack *stack, int index, int value);
void	stack_eraser(t_stack *stack);

///////////////// SORTING ////////////////////////
void	sort(t_stack *stack_a, t_stack *stack_b, int *nb_str, int len);
int		check_sorted(t_stack *stack);

/////////////// MISCELLANEOUS //////////////
int		counter(t_node *stack, int i);
int		get_min(t_node *stack);
void	stack_inner_freer(t_stack *stack);

#endif