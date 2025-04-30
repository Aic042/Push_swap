/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:04:52 by root              #+#    #+#             */
/*   Updated: 2025/04/29 14:56:34 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
				return (1);
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

int	is_nbr(char *str)
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

int	parse_args(int argc, char **argv)
{
	char	*joined;
	char	**split;
	int		*numbers;
	int		i;

	numbers = malloc(sizeof(int) * i);
	if (!numbers)
	{
		free_split(split);
		return (0);
	}

	joined = join_args(argc, argv);
	if (!joined)
		return (0);
	split = ft_split(joined, ' ');
	free(joined);
	if (!split)
		return (0);
	i = 0;
	while (split[i] && is_nbr(split[i]))
		i++;
	if (split[i])
		return (free_split(split), 0);
	while (--i >= 0)
		numbers[i] = ft_atoi(split[i]);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (!check_dups(numbers, i) && (free(numbers), 1));
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (!parse_args(argc, argv))
	{
		write(1, "Error with the parsing", 23);
		return (1);
	}
	return (0);
}