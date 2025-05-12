/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:04:52 by root              #+#    #+#             */
/*   Updated: 2025/05/11 23:11:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dups(int *num_array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (num_array[i] == num_array[j])
				return (free(num_array), write(1, "Error\n", 6), 1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	is_numr(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	count_args(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

int	parse_args(int argc, char **argv, int **num_array, int *count)
{
	char	*joined;
	char	**split;
	int		i;

	joined = join_args(argc, argv);
	if (!joined)
		return (0);
	split = ft_split(joined, ' ');
	free(joined);
	if (!split)
		return (0);
	*count = count_args(split);
	*num_array = malloc(sizeof(int) * (*count));
	if (!*num_array)
		return (free_split(split), 0);
	i = 0;
	while (i < *count)
	{
		if (!is_numr(split[i]) || ft_atol(split[i]) > INT_MAX
			|| ft_atol(split[i]) < INT_MIN)
			return (free_split(split), free(*num_array), print_error(), 1);
		(*num_array)[i] = ft_atoi(split[i]);
		i++;
	}
	return (free_split(split), !check_dups(*num_array, *count));
}

// Prototype V1.0
// int	parse_args(int argc, char **argv)
// {
// 	char	*joined;
// 	char	**split;
// 	int		*numbers;
// 	int		i;
// 	i = 0;

// 	numbers = malloc(sizeof(int));
// 	if (!numbers)
// 		exit (1);
// 	// return (free_split(split), 0);
// 	joined = join_args(argc, argv);
// 	if (!joined)
// 		return (0);
// 	split = ft_split(joined, ' ');
// 	free(joined);
// 	if (!split)
// 		exit (1);
// 	i = 0;
// 	while (split[i] && is_numr(split[i]))
// 		i++;
// 	if (split[i])
// 		return (free_split(split), 0);
// 	while (--i >= 0)
// 		numbers[i] = ft_atoi(split[i]);
// 	i = 0;
// 	while (split[i])
// 		free(split[i++]);
// 	free(split);
// 	return (!check_dups(numbers, i) && (free(numbers), 1));
// }
