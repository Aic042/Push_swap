/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_joiner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 07:23:55 by root              #+#    #+#             */
/*   Updated: 2025/04/30 11:04:06 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*join_args(int argc, char **argv)
{
	char	*joined;
	char	*tmp;
	int		i;

	joined = ft_strdup("");
	if (!joined)
		return (NULL);
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
