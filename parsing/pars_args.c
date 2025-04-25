/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:10:00 by aingunza          #+#    #+#             */
/*   Updated: 2025/04/25 13:02:10 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv))
	{
		write(1, "Error with the parsing", 23);
		return (1);
	}
	return (0);
}
