/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:04:52 by root              #+#    #+#             */
/*   Updated: 2025/04/16 08:27:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*join_args(int argc, char **argv)
{
	char	*joined;
	char	*tmp;
	int		i;

	joined = ft_strdup("");
	if (!joined)
		return(NULL);
	i = 1;
	while (i < argc)
	{
		tmp = ft_strjoin(joined, argv[i]);
		free(joined);
		if (!tmp)
			return (NULL);
		joined = tmp;
		tmp = ft_strjoin(joined, " ");
		free(joined);
		if (!tmp)
			return (NULL);
		joined = tmp;
		i++;
	}
	return (joined);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
